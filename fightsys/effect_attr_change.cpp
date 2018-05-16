#include <intsafe.h>
#include "effect_attr_change.h"
#include "attr_sys.h"
#include "role_agent.h"

EffectAttrChange::EffectAttrChange()
{
	m_attr_id = 0;
	m_val = 0;
	m_per = 0;
}

EffectAttrChange::~EffectAttrChange()
{
}

bool EffectAttrChange::load(ConfigBasePtr cb)
{
	if (!IsValidAttrID(m_attr_id)) {
		return false;
	}

	return true;
}

bool EffectAttrChange::check(RoleAgentPtr ra, SkillProcessPtr sp)
{
	return true;
}

bool EffectAttrChange::run(RoleAgentPtr ra, SkillProcessPtr sp)
{
	ra->GetAttr()->ChangeVal(m_attr_id, m_val);
	ra->GetAttr()->ChangePer(m_attr_id, m_per);
	return true;
}
