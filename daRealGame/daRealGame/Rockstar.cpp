#include "Rockstar.h"

Rockstar::Rockstar(HTEXTURE tex, Input *mIn) : Playable(tex, mIn)
{
	characterType = 1;
	
	my_ranged_speed *= 1.5;
}

Rockstar::~Rockstar(void)
{
}
