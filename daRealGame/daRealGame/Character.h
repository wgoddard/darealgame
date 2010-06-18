#pragma once

#include "Collidable.h"
#include "hgeSprite.h"
#include <iostream>

enum States { IDLE, WALK, MELEE, RANGED, SPECIAL, DEATH, VICTORY, EXTRA };

class Character:
	public Collidable
{
protected:
	int my_health;
	int my_max_health;
	bool my_alive;

	float my_attack_speed;
	float my_ranged_speed;

	float my_hspeed;
	float my_vspeed;

	int my_score;
	int my_given_kill_score;

	hgeSprite *my_sprite;

	int my_frames[8];
	float my_fp_sec[8];
	int spriteWidth;
	int spriteHeight;

	bool flipped;

	float frameTimer;
	int cFrame;

	States my_state;
	float my_x;
	float my_y;
	float my_z;
public:
	Character(HTEXTURE tex);
	virtual ~Character(void);

	void hit(Character *other, int damage);
	virtual void melee(){};
	void addScore(int score){ my_score += score; }

	int getScore(){ return my_score; }
	int getHealth(){ return (int)my_health; }
	int getMaxHealth(){ return (int)my_max_health; }
	bool isAlive(){ return my_alive; }

	void move(float x, float y){ my_x = x; my_y = y; }

	void Update(float &dt, float rel_x_speed);
	void Render();
};