#pragma once
#include "playable.h"

class Janitor :
	public Playable
{
public:
	Janitor(HTEXTURE tex, Input *mIn);
	~Janitor(void);

	void Melee() {};
	void Ranged() {};
};
