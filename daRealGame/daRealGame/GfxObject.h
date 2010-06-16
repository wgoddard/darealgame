#pragma once
#include "collidable.h"

class GfxObject :
	public Collidable
{
public:
	GfxObject(void);
	virtual ~GfxObject(void);
};
