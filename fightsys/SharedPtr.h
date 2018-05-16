#pragma once

#include <memory>

class SkillBase;
class SkillProcess;
class RoleAgent;
class ConfigBase;
class CheckBase;
class EffectBase;
class AttrSys;

typedef std::shared_ptr<SkillBase>    SkillBasePtr;
typedef std::shared_ptr<SkillProcess> SkillProcessPtr;
typedef std::shared_ptr<RoleAgent>    RoleAgentPtr;
typedef std::shared_ptr<ConfigBase>   ConfigBasePtr;
typedef std::shared_ptr<CheckBase>    CheckBasePtr;
typedef std::shared_ptr<EffectBase>   EffectBasePtr;
typedef std::shared_ptr<AttrSys>      AttrSysPtr;

