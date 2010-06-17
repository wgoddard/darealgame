#pragma once
#include "collidable.h"

#include "hgeAnim.h"

class GfxObject :
	public Collidable
{
protected:
	hgeAnimation* my_sprite;
public:
	GfxObject(HTEXTURE res);
	virtual ~GfxObject(void);
};
