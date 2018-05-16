#pragma once

#include "SharedPtr.h"

class RoleAgent
{
public:
	RoleAgent();
	~RoleAgent();

	AttrSysPtr GetAttr();
	SkillProcessPtr GetCurrSkill();

private:
	AttrSysPtr      m_Attrs;
	SkillProcessPtr	m_CurrSkill;	
};
