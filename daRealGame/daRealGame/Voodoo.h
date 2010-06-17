#pragma once
#include "playable.h"

class Voodoo :
	public Playable
{
public:
	Voodoo(HTEXTURE tex, Input *mIn);
	~Voodoo(void);
};
