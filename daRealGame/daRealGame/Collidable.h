#pragma once
#include "object.h"

#include "hgeRect.h"

class Collidable :
	public Object
{
protected:
	hgeRect *my_rect;
public:
	Collidable();
	~Collidable(void);

	bool doesCollide(Collidable &other){ return my_rect->Intersect(other.getHitRect()); }
	hgeRect* getHitRect(){ return my_rect; }
};
