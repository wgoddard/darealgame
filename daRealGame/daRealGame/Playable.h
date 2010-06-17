#pragma once
#include "character.h"

#include "Input.h"

class Playable :
	public Character
{
protected:
	//getting
	//float my_max_health;
	//float my_attack_speed;
	//float my_ranged_speed;
	//int my_hspeed;
	//int my_vspeed;

	States my_state;

	int characterType;
	int numKills;

	Input *my_input;
public:
	Playable(HTEXTURE tex, Input *mIn);
	~Playable(void);

	int getCharacterType(){ return characterType; }

	void Update(float &dt, float rel_x_speed);
};
