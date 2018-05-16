#pragma once

#include "fight_base.h"

// Ð§¹ûÆ÷
class EffectAttrChange : public EffectBase
{
public:
	EffectAttrChange();
	~EffectAttrChange();

	virtual bool load(ConfigBasePtr cb) = 0;
	virtual bool check(RoleAgentPtr ra, SkillProcessPtr sp) = 0;
	virtual bool run(RoleAgentPtr ra, SkillProcessPtr sp) = 0;
protected:
	int m_attr_id;
	int m_val;
	int m_per;
};
