#pragma once
#include "gfxobject.h"

enum States { IDLE, WALK, MELEE, RANGED, SPECIAL, DEATH, VICTORY, JUMP };

class Character :
	public GfxObject
{
protected:
	int my_health;
	int my_max_health;

	float my_attack_speed;
	float my_ranged_speed;

	float my_hspeed;
	float my_vspeed;

	int my_score;
	int my_given_kill_score;
public:
	Character(HTEXTURE tex);
	virtual ~Character(void);

	void hit(Character &other, int damage);
	void addScore(int score){ my_score += score; }

	int getScore(){ return my_score; }
	int getHealth(){ return (int)my_health; }
	int getMaxHealth(){ return (int)my_max_health; }

	void Update(float &dt);
	void Render();
};