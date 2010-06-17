#pragma once
#include "playable.h"

class Rockstar :
	public Playable
{
public:
	Rockstar(HTEXTURE tex, Input *mIn);
	~Rockstar(void);
};
