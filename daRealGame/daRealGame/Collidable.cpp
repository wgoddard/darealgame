#include "Collidable.h"

Collidable::Collidable()
{
	my_rect = new hgeRect();
}

Collidable::~Collidable(void)
{
	delete my_rect;
}
