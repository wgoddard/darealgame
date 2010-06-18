#pragma once
#include "playable.h"

class Rockstar :
	public Playable
{
public:
	Rockstar(HTEXTURE tex, Input *mIn);
	~Rockstar(void);

	void Update(float &dt, float rel_x_speed);
	void Melee();
	void Ranged() {};
};