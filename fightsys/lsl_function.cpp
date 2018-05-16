#include "lsl_function.h"
#include "lsl_param.h"
#include "lsl_app.h"

Lsl_Func::Lsl_Func()
{
}

Lsl_Func::~Lsl_Func()
{
}
void Lsl_Func::SetMyApp(Lsl_AppPtr a)
{
	m_MyApp = a;
}

Lsl_AppPtr  Lsl_Func::GetMyApp()
{
	return m_MyApp;
}

bool Lsl_Func::LoadFromString(std::string s)
{
	Lsl_FN_Call* x = new Lsl_FN_Call();
	x->LoadFromString(s);
	Lsl_FNPtr fn = std::shared_ptr<Lsl_FN_Call>(x);
	m_Nodes = fn;
	m_Stack.push_back(fn);
	return true;
}

void Lsl_Func::SetParams(Lsl_ParamPtr p)
{
	m_Params = p;
}

Lsl_ParamPtr Lsl_Func::GetReturns()
{
	return m_Returns;
}

void Lsl_Func::Run()
{
	if (m_Stack.size()>0) {
		Lsl_FNPtr x = m_Stack.front();
		if (x)
			x->Run(shared_from_this());
	}
}



Lsl_FN::Lsl_FN()
{
	m_Prev = NULL;
	m_Next = NULL;
	m_Child = NULL;
}

Lsl_FN::~Lsl_FN()
{
}

Lsl_FN_Call::Lsl_FN_Call()
{
}

Lsl_FN_Call::~Lsl_FN_Call()
{
}
bool Lsl_FN_Call::LoadFromString(std::string s)
{
	if (s == "Eat") {
		m_FuncName = "Sleep";
		m_Params = Lsl_ParamPtr(new Lsl_Param);
		m_Params->m_Strings.m_StringMap.insert(std::map<std::string, int>::value_type("msg", 1));
		m_Params->m_Strings.m_Strings.push_back("ÄãºÃ");
	}
	else {
		m_FuncName = "Print";
		m_Params = Lsl_ParamPtr(new Lsl_Param);
		m_Params->m_Strings.m_StringMap.insert(std::map<std::string, int>::value_type("msg", 1));
		m_Params->m_Strings.m_Strings.push_back("ÄãºÃ");
	}
	return true;
}

void Lsl_FN_Call::Run(Lsl_FuncPtr f)
{
	f->GetMyApp()->CallFunc(m_FuncName, m_Params);
}
