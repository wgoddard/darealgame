#include "Ninja.h"

Ninja::Ninja(b2Body * body, HTEXTURE tex, Input *mIn) : Playable(body, tex, mIn)
{
	characterType = 2;
}

Ninja::~Ninja(void)
{
}
