#include "Janitor.h"

Janitor::Janitor(b2Body * body, HTEXTURE tex, Input *mIn) : Playable(body, tex, mIn)
{
	characterType = 0;
}

Janitor::~Janitor(void)
{
}
