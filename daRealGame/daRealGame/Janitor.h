#pragma once
#include "playable.h"

class Janitor :
	public Playable
{
public:
	Janitor(b2Body * body, HTEXTURE tex, Input *mIn);
	~Janitor(void);
};
