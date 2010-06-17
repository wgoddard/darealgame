#pragma once
#include "playable.h"

class Voodoo :
	public Playable
{
public:
	Voodoo(b2Body * body, HTEXTURE tex, Input *mIn);
	~Voodoo(void);
};
