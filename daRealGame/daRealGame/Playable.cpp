#include "Playable.h"

Playable::Playable(HTEXTURE tex, Input *mIn) : Character(tex)
{
	characterType = 0;
	my_state = IDLE;

	my_input = mIn;
	numKills = 0;
}

Playable::~Playable(void)
{
	
}
