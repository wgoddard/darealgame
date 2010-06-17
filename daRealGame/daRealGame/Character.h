#pragma once
#include "gfxobject.h"

class Character :
	public GfxObject
{
protected:
	float my_health;
	float my_max_health;
	float my_attack_speed;
	int my_score;
	int my_given_kill_score;
public:
	Character(b2Body * body, HTEXTURE tex);
	virtual ~Character(void);

	void hit(Character &other, int damage);
	void addScore(int score){ my_score += score; }

	int getScore(){ return my_score; }
	int getHealth(){ return (int)my_health; }
	int getMaxHealth(){ return (int)my_max_health; }
};