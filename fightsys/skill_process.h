#pragma once

#include "SharedPtr.h"

// 技能执行过程数据
class SkillProcess
{
public:
	SkillProcess();

	~SkillProcess();

private:
	SkillBasePtr	m_CurrSkill;
};
