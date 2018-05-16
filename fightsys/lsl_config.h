#pragma once
#include "lsl_script.h"

class Lsl_Config
{
	typedef std::map<std::string, Lsl_FuncPtr> FuncMap;
public:
	Lsl_Config();
	~Lsl_Config();

	bool LoadConfig(std::string file_name);
	bool LoadConfigFromString(std::string s);

	Lsl_FuncPtr GetFunc(std::string func_name);

private:
	FuncMap	m_Funcs;
};

Lsl_ConfigPtr GetLslConfig();
