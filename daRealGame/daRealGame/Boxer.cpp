#include "Boxer.h"

Boxer::Boxer(HTEXTURE tex) : AICharacter(tex)
{
	my_health = 1;
	my_max_health = my_health;

	my_attack_speed = 0;
	my_ranged_speed = 0;

	my_hspeed = 100;
	my_vspeed = 50;

	my_given_kill_score = 500;

	//my_frames[8];
	//my_fp_sec[8];

	my_frames[IDLE] = 1;
	my_frames[WALK] = 2;
	my_frames[MELEE] = 6;
	my_frames[SPECIAL] = 1;
	my_frames[DEATH] = 4;
	my_frames[EXTRA] = 1;

	spriteWidth = 128;
	spriteHeight = 128;

	flipped = false;
}

Boxer::~Boxer(void)
{
}

void Boxer::Update(float &dt, float rel_x_speed){
	AICharacter::Update(dt, rel_x_speed);

	my_rect->x1 = my_x;
	my_rect->x2 = my_x + spriteWidth;
	my_rect->y1 = my_y + spriteHeight - 35;
	my_rect->y2 = my_y + spriteHeight + 5;
}