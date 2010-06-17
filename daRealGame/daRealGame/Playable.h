#pragma once
#include "character.h"

#include "Input.h"

enum States { IDLE, WALK, MELEE, RANGED, SPECIAL, DEATH, VICTORY, JUMP };

class Playable :
	public Character
{
protected:
	int my_hspeed;
	int my_vspeed;

	States my_state;

	int characterType;
	int numKills;

	Input *my_input;
public:
	Playable(b2Body * body, HTEXTURE tex, Input *mIn);
	~Playable(void);

	int getCharacterType(){ return characterType; }
};
