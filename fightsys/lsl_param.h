#pragma once
#include "lsl_script.h"

class Lsl_Param
{
public:
	struct NumberSet {
		std::map<std::string, int>	m_NumberMap;	// 变量名映射表 (数)
		std::vector<INT64>			m_Numbers;		// 变量集合     (数)
	};
	struct StringSet {
		std::map<std::string, int>	m_StringMap;	// 变量名映射表 (字符串)
		std::vector<std::string>	m_Strings;		// 变量集合     (字符串)
	};
	struct NumberArraySet {
		std::map<std::string, int>					m_NumberMap;	// 变量名映射表 (数)
		std::vector<std::vector<INT64> >			m_Numbers;		// 变量集合     (数)
	};
	struct StringArraySet {
		std::map<std::string, int>					m_StringMap;	// 变量名映射表 (数)
		std::vector<std::vector<std::string> >		m_Strings;		// 变量集合     (数)
	};

	NumberSet		m_Numbers;
	StringSet		m_Strings;
	NumberArraySet	m_NumberArrays;
	StringArraySet	m_StringArrays;
};

