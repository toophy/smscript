#pragma once

#include "fight_base.h"

// ¼ì²éÆ÷
class CheckAttrLimit : public CheckBase
{
public:
	CheckAttrLimit();
	~CheckAttrLimit();
	virtual bool load(ConfigBasePtr cb);
	virtual bool check(RoleAgentPtr ra, SkillProcessPtr sp);
protected:
	int m_attr_id;
	int m_min;
	int m_max;
};
