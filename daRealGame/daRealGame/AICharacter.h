#pragma once
#include "character.h"

class AICharacter :
	public Character
{
public:
	AICharacter(HTEXTURE tex);
	~AICharacter(void);

	virtual void Update(float &dt, float x_scroll){ Character::Update(dt, x_scroll); };
};
