#pragma once
#include "object.h"

#include "box2d.h"

class Collidable :
	public Object
{
protected:
	b2Body* my_body;
public:
	Collidable(b2Body *body);
	~Collidable(void);

	b2Body* getBody(){ return my_body; }
};
