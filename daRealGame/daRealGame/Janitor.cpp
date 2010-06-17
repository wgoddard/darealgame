#include "Janitor.h"

Janitor::Janitor(HTEXTURE tex, Input *mIn) : Playable(tex, mIn)
{
	characterType = 0;

	my_attack_speed *= 1.5;
}

Janitor::~Janitor(void)
{
}
