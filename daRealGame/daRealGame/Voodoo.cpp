#include "Voodoo.h"

Voodoo::Voodoo(b2Body * body, HTEXTURE tex, Input *mIn) : Playable(body, tex, mIn)
{
	characterType = 3;
}

Voodoo::~Voodoo(void)
{
}
