#pragma once
#include "playable.h"

class Ninja :
	public Playable
{
public:
	Ninja(HTEXTURE tex, Input *mIn);
	~Ninja(void);
};
