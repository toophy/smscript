#pragma once
#include "lsl_script.h"

class Lsl_Func : public std::enable_shared_from_this<Lsl_Func>
{
public:
	Lsl_Func();
	~Lsl_Func();

	bool LoadFromString(std::string s);

	void SetMyApp(Lsl_AppPtr a);
	Lsl_AppPtr GetMyApp();
	void SetParams(Lsl_ParamPtr p);
	void Run();
	Lsl_ParamPtr GetReturns();

private:
	Lsl_AppPtr				m_MyApp;
	Lsl_ParamPtr			m_Params;
	Lsl_ParamPtr			m_Returns;
	Lsl_ParamPtr			m_Blackboard;
	Lsl_FNPtr				m_Nodes;
	std::deque<Lsl_FNPtr>	m_Stack;
};

class Lsl_FN
{
public:
	Lsl_FN();
	virtual ~Lsl_FN();

	Lsl_FN* m_Prev;
	Lsl_FN* m_Next;
	Lsl_FN* m_Child;

	virtual bool LoadFromString(std::string s){ return true; }
	virtual void Run(Lsl_FuncPtr f){}
};

class Lsl_FN_Call : public Lsl_FN
{
	friend class Lsl_Func;
public:
	Lsl_FN_Call();
	virtual ~Lsl_FN_Call();

	virtual bool LoadFromString(std::string s);
	virtual void Run(Lsl_FuncPtr f);

private:
	std::string		m_FuncName;
	Lsl_ParamPtr	m_Params;
};

