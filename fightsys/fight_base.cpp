#include "fight_base.h"


CheckBase::CheckBase()
{
}

CheckBase::~CheckBase()
{
}

EffectBase::EffectBase()
{
}

EffectBase::~EffectBase()
{
}

SkillBase::SkillBase()
{
}

SkillBase::~SkillBase()
{
}

bool SkillBase::load(ConfigBasePtr cb)
{
	// 自身
	// 新增 check
	// 新增 effect
	return false;
}

bool SkillBase::check(RoleAgentPtr ra, SkillProcessPtr sp)
{
	for (size_t i = 0; i < m_Checks.size(); ++i)
	{
		if (m_Checks[i]) {
			if (!m_Checks[i]->check(ra, sp)) {
				return false;
			}
		}
	}
	return true;
}

bool SkillBase::run(RoleAgentPtr ra, SkillProcessPtr sp)
{
	for (size_t i = 0; i < m_Checks.size(); i++)
	{
		if (m_Effects[i]) {
			if (!m_Effects[i]->check(ra,sp)) {
				m_Effects[i]->run(ra, sp);
			}			
		}
	}
	return true;
}


