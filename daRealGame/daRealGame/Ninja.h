#pragma once
#include "playable.h"

class Ninja :
	public Playable
{
public:
	Ninja(b2Body * body, HTEXTURE tex, Input *mIn);
	~Ninja(void);
};
