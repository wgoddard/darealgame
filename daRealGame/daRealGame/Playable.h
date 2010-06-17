#pragma once
#include "character.h"

class Playable :
	public Character
{
public:
	Playable(b2Body * body, HTEXTURE tex);
	~Playable(void);
};
