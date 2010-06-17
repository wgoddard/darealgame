#pragma once
#include "playable.h"

class Rockstar :
	public Playable
{
public:
	Rockstar(b2Body * body, HTEXTURE tex, Input *mIn);
	~Rockstar(void);
};
