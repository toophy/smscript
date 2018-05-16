#include "lsl_config.h"
#include "lsl_function.h"
#include "lsl_param.h"

Lsl_ConfigPtr g_LslConfig;
Lsl_ConfigPtr GetLslConfig()
{
	if (!g_LslConfig) {
		g_LslConfig = Lsl_ConfigPtr(new Lsl_Config);
	}
	return g_LslConfig;
}

Lsl_Config::Lsl_Config()
{
}

Lsl_Config::~Lsl_Config()
{
}

bool Lsl_Config::LoadConfig(std::string file_name)
{
	return true;
}

bool Lsl_Config::LoadConfigFromString(std::string s)
{
	std::string func_name = "Eat";
	Lsl_FuncPtr pf = Lsl_FuncPtr(new Lsl_Func);
	m_Funcs.insert(FuncMap::value_type(func_name, pf));
	pf->LoadFromString("");

	return true;
}

Lsl_FuncPtr Lsl_Config::GetFunc(std::string func_name)
{
	FuncMap::iterator it = m_Funcs.find(func_name);
	if (it!=m_Funcs.end()) {
		return it->second;
	}
	return Lsl_FuncPtr();
}

