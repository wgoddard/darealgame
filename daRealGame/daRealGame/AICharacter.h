#pragma once
#include "character.h"

class AICharacter :
	public Character
{
public:
	AICharacter(b2Body * body, HTEXTURE tex);
	~AICharacter(void);
};
