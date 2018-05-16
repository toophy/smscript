#pragma once

#include <intsafe.h>
#include <vector>

enum {
	ATTR_None,

	ATTR_Level,
	ATTR_HP,
	ATTR_MP,
	ATTR_MaxHP,
	ATTR_MaxMP,


	ATTR_MaxID
};

struct Attr{
	INT64  base;
	INT64  val;
	INT64  per;
	INT64  last;
	bool   change;

	Attr();
};

inline bool IsValidAttrID(int id){
	return id > 0 && id < ATTR_MaxID;
}

class AttrSys
{
public:
	AttrSys();
	~AttrSys();

	Attr GetAttr(UINT attr_id);
	INT64 GetAttrBase(UINT attr_id);
	INT64 GetAttrChangeVal(UINT attr_id);
	INT64 GetAttrChangePer(UINT attr_id);
	INT64 GetAttrLast(UINT attr_id);

	void ChangeBase(UINT attr_id, INT base);
	void ChangeVal(UINT attr_id, INT val);
	void ChangePer(UINT attr_id, INT per);
	void ApplyChange();

private:
	void applyChange(UINT attr_id);

private:
	Attr m_Attrs[ATTR_MaxID-1];
};
