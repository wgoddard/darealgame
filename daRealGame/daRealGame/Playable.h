#pragma once
#include "character.h"

#include <vector>

#include "Input.h"
#include "KillSquare.h"

extern std::vector<KillSquare*> playerHazards;

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

	//States my_state;

	int characterType;
	int numKills;
	float secTimer;

	Input *my_input;
public:
	Playable(HTEXTURE tex, Input *mIn);
	~Playable(void);

	int getCharacterType(){ return characterType; }

	virtual void Update(float &dt, float rel_x_speed);
	virtual void Melee() = 0;
	virtual void Ranged() = 0;

	Input* getInput(){ return my_input; }
};
