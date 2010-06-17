#include "Playable.h"

Playable::Playable(b2Body * body, HTEXTURE tex, Input *mIn) : Character(body, tex)
{
	characterType = 0;
	my_state = IDLE;

	my_input = mIn;
	numKills = 0;
}

Playable::~Playable(void)
{
	
}
