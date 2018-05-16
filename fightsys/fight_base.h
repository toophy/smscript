#pragma once

#include <vector>
#include "SharedPtr.h"


// 检查器
class CheckBase
{
public:
	CheckBase();
	~CheckBase();
	virtual bool load(ConfigBasePtr cb) = 0;
	virtual bool check(RoleAgentPtr ra, SkillProcessPtr sp) = 0;
};

// 效果器
class EffectBase
{
public:
	EffectBase();
	~EffectBase();

	virtual bool load(ConfigBasePtr cb) = 0;
	virtual bool check(RoleAgentPtr ra, SkillProcessPtr sp) = 0;
	virtual bool run(RoleAgentPtr ra, SkillProcessPtr sp) = 0;
};


// 技能基本能力
class SkillBase
{
public:
	SkillBase();
	~SkillBase();

	virtual bool load(ConfigBasePtr cb);
	virtual bool check(RoleAgentPtr ra, SkillProcessPtr sp);
	virtual bool run(RoleAgentPtr ra, SkillProcessPtr sp);

private:
	std::vector<CheckBasePtr> m_Checks;
	std::vector<EffectBasePtr> m_Effects;
};
