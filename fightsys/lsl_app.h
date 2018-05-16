#pragma once
#include "lsl_script.h"

class Lsl_App : public std::enable_shared_from_this<Lsl_App>
{
	friend class Lsl_Func;
public:

	typedef Lsl_ParamPtr(Lsl_App::*HostFunc)(Lsl_ParamPtr params);

	struct CallStack	{
		Lsl_FuncPtr		scriptFunc;
		HostFunc		hostFunc;
		Lsl_ParamPtr	params;
		Lsl_ParamPtr	returns;

		CallStack(){
			hostFunc = NULL;
		}
	};

public:
	Lsl_App();
	~Lsl_App();

	Lsl_AppPtr GetPtr();

	bool RunScript(std::string func_name, Lsl_ParamPtr params);

	bool CallFunc(std::string func_name, Lsl_ParamPtr params);

private:
	bool RegistHostFunc(std::string func_name, HostFunc hf);

private:
	Lsl_ParamPtr Print(Lsl_ParamPtr params);
	Lsl_ParamPtr GetBlackboard(Lsl_ParamPtr params);

private:
	std::map<std::string, HostFunc>		m_HostFuns;
	std::deque<CallStack>				m_FuncStack;
	Lsl_ParamPtr						m_Blackboard;

};


