#include "Collidable.h"

Collidable::Collidable(b2Body *body)
{
	my_body = body;
}

Collidable::~Collidable(void)
{
}
