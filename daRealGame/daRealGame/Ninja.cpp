#include "Ninja.h"

Ninja::Ninja(HTEXTURE tex, Input *mIn) : Playable(tex, mIn)
{
	characterType = 2;
	
	my_hspeed *= 1.5;
	my_vspeed *= 1.5;
}

Ninja::~Ninja(void)
{
}
