#pragma once
#include "lsl_script.h"

class Lsl_Param
{
public:
	struct NumberSet {
		std::map<std::string, int>	m_NumberMap;	// ������ӳ��� (��)
		std::vector<INT64>			m_Numbers;		// ��������     (��)
	};
	struct StringSet {
		std::map<std::string, int>	m_StringMap;	// ������ӳ��� (�ַ���)
		std::vector<std::string>	m_Strings;		// ��������     (�ַ���)
	};
	struct NumberArraySet {
		std::map<std::string, int>					m_NumberMap;	// ������ӳ��� (��)
		std::vector<std::vector<INT64> >			m_Numbers;		// ��������     (��)
	};
	struct StringArraySet {
		std::map<std::string, int>					m_StringMap;	// ������ӳ��� (��)
		std::vector<std::vector<std::string> >		m_Strings;		// ��������     (��)
	};

	NumberSet		m_Numbers;
	StringSet		m_Strings;
	NumberArraySet	m_NumberArrays;
	StringArraySet	m_StringArrays;
};

