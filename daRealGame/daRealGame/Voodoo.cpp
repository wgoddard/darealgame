#include "Voodoo.h"

Voodoo::Voodoo(HTEXTURE tex, Input *mIn) : Playable(tex, mIn)
{
	characterType = 3;

	my_max_health *= 1.5;
	my_health = my_max_health;
	my_attack_speed = 3;
	my_ranged_speed = 2;
	my_hspeed = 10;
	my_vspeed = 10;
}

Voodoo::~Voodoo(void)
{
}
