#pragma once

#include "SharedPtr.h"

// ����ִ�й�������
class SkillProcess
{
public:
	SkillProcess();

	~SkillProcess();

private:
	SkillBasePtr	m_CurrSkill;
};
