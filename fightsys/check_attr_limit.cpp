#include <intsafe.h>
#include "check_attr_limit.h"
#include "attr_sys.h"
#include "role_agent.h"

CheckAttrLimit::CheckAttrLimit()
{
	m_attr_id = 0;
	m_min = 0;
	m_max = 0;
}

CheckAttrLimit::~CheckAttrLimit()
{
}

bool CheckAttrLimit::load(ConfigBasePtr cb)
{
	// 从配置 cb 加载参数

	if (!IsValidAttrID(m_attr_id)) {
		return false;
	}
	if (m_min<0 && m_max<0) {
		return false;
	}

	return true;
}

bool CheckAttrLimit::check(RoleAgentPtr ra, SkillProcessPtr sp)
{
	UINT64 v = ra->GetAttr()->GetAttrLast(m_attr_id);

	if (m_min < 0) {
		return v <= m_max;
	}
	else if (m_max < 0) {
		return v >= m_min;
	}

	return m_min <= v && v <= m_max;
}

