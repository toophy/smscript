#include "lsl_app.h"
#include "lsl_param.h"
#include "lsl_config.h"
#include "lsl_function.h"

Lsl_App::Lsl_App()
{
	RegistHostFunc("Print", &Lsl_App::Print);
	RegistHostFunc("GetBlackboard", &Lsl_App::GetBlackboard);
}

Lsl_App::~Lsl_App()
{
}

Lsl_AppPtr Lsl_App::GetPtr()
{
	return this->shared_from_this();
}

bool Lsl_App::RunScript(std::string func_name, Lsl_ParamPtr params)
{
	
	Lsl_FuncPtr fp = GetLslConfig()->GetFunc(func_name);
	if (!fp) {
		return false;
	}

	CallStack x;

	x.scriptFunc = fp;
	x.params = params;

	Lsl_AppPtr pThis = GetPtr();
	fp->SetMyApp(pThis);
	fp->SetParams(params);

	m_FuncStack.push_back(x);

	fp->Run();

	m_FuncStack.pop_back();

	return true;
}

bool Lsl_App::CallFunc(std::string func_name, Lsl_ParamPtr params)
{
	std::map<std::string, HostFunc>::iterator it = m_HostFuns.find(func_name);
	if (it != m_HostFuns.end()) {
		(this->*(it->second))(params);
	}
	return false;
}

bool Lsl_App::RegistHostFunc(std::string func_name, HostFunc hf)
{
	m_HostFuns.insert(std::map<std::string, HostFunc>::value_type(func_name, hf));
	return true;
}

Lsl_ParamPtr Lsl_App::Print(Lsl_ParamPtr params)
{
	printf(params->m_Strings.m_Strings.at(0).c_str());
	return Lsl_ParamPtr();
}

Lsl_ParamPtr Lsl_App::GetBlackboard(Lsl_ParamPtr params)
{
	return m_Blackboard;
}
