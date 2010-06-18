#pragma once
#include "aicharacter.h"

class Boxer :
	public AICharacter
{
public:
	Boxer(HTEXTURE tex);
	~Boxer(void);

	void Update(float &dt, float rel_x_speed);
};
