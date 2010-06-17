#pragma once
#include "collidable.h"

#include "hgeAnim.h"

class GfxObject :
	public Collidable
{
protected:
	hgeAnimation* my_anim;
public:
	GfxObject(b2Body *body, HTEXTURE res);
	virtual ~GfxObject(void);
};
