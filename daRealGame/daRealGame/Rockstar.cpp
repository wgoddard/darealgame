#include "Rockstar.h"

Rockstar::Rockstar(b2Body * body, HTEXTURE tex, Input *mIn) : Playable(body, tex, mIn)
{
	characterType = 1;
}

Rockstar::~Rockstar(void)
{
}
