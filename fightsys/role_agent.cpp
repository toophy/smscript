#include "role_agent.h"
#include "skill_process.h"
#include "attr_sys.h"

RoleAgent::RoleAgent()
{
	m_CurrSkill = SkillProcessPtr(new SkillProcess);
}

RoleAgent::~RoleAgent()
{
}

AttrSysPtr RoleAgent::GetAttr()
{
	return m_Attrs;
}

SkillProcessPtr RoleAgent::GetCurrSkill()
{
	return m_CurrSkill;
}
