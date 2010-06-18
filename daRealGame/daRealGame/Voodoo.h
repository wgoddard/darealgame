#pragma once
#include "playable.h"

class Voodoo :
	public Playable
{
public:
	Voodoo(HTEXTURE tex, Input *mIn);
	~Voodoo(void);

	void Update(float &dt, float rel_x_speed);
	void Melee();
};
