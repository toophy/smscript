#include "attr_sys.h"

Attr::Attr() :
base(0),
val(0),
per(0),
last(0),
change(false)
{
}


AttrSys::AttrSys()
{
}

AttrSys::~AttrSys()
{
}

Attr AttrSys::GetAttr(UINT attr_id)
{
	Attr a;
	if (IsValidAttrID(attr_id)) {
		return m_Attrs[attr_id - 1];
	}
	return a;
}

INT64 AttrSys::GetAttrBase(UINT attr_id)
{
	if (IsValidAttrID(attr_id)) {
		return m_Attrs[attr_id - 1].base;
	}
	return 0;
}

INT64 AttrSys::GetAttrChangeVal(UINT attr_id)
{
	if (IsValidAttrID(attr_id)) {
		return m_Attrs[attr_id - 1].val;
	}
	return 0;
}

INT64 AttrSys::GetAttrChangePer(UINT attr_id)
{
	if (IsValidAttrID(attr_id)) {
		return m_Attrs[attr_id - 1].per;
	}
	return 0;
}

INT64 AttrSys::GetAttrLast(UINT attr_id)
{
	if (IsValidAttrID(attr_id)) {
		return m_Attrs[attr_id - 1].last;
	}
	return 0;
}

void AttrSys::ChangeBase(UINT attr_id, INT base)
{
	if (IsValidAttrID(attr_id)) {
		m_Attrs[attr_id - 1].base += base;
		m_Attrs[attr_id - 1].change = true;
	}
}

void AttrSys::ChangeVal(UINT attr_id, INT val)
{
	if (IsValidAttrID(attr_id)) {
		m_Attrs[attr_id - 1].val += val;
		m_Attrs[attr_id - 1].change = true;
	}
}

void AttrSys::ChangePer(UINT attr_id, INT per)
{
	if (IsValidAttrID(attr_id)) {
		m_Attrs[attr_id - 1].per += per;
		m_Attrs[attr_id - 1].change = true;
	}
}

void AttrSys::applyChange(UINT attr_id)
{
	Attr& a = m_Attrs[attr_id - 1];
	a.last = (a.base + a.val) * (100 + a.per) / 100;
}

void AttrSys::ApplyChange()
{
	for (int i = 0; i < ATTR_MaxID; ++i) {
		if (m_Attrs[i].change) {
			Attr& a = m_Attrs[i];
			a.last = (a.base + a.val) * (100 + a.per) / 100;
		}
	}
}
