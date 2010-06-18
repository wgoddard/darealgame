#include "Rockstar.h"

Rockstar::Rockstar(HTEXTURE tex, Input *mIn) : Playable(tex, mIn)
{
	characterType = 1;
	
	my_ranged_speed *= 1.5;

	spriteWidth = 178;
	spriteHeight = 128;

	my_x = 400;

	//enum States { IDLE, WALK, MELEE, RANGED, SPECIAL, DEATH, VICTORY, EXTRA };
	
	my_frames[IDLE] = 2;
	my_frames[WALK] = 2;
	my_frames[MELEE] = 4;
	my_fp_sec[MELEE] = 0.1f;
	my_frames[RANGED] = 2;
	my_frames[SPECIAL] = 5;
	my_frames[EXTRA] = 1;
}

Rockstar::~Rockstar(void)
{

}

void Rockstar::Update(float &dt, float rel_x_speed){
	Playable::Update(dt, rel_x_speed);

	my_rect->y1 = my_y + spriteHeight - 20;
	my_rect->y2 = my_y + spriteHeight;

	if(flipped){
		my_rect->x1 = my_x + 20;
		my_rect->x2 = my_x + 100;
	} else {
		my_rect->x1 = my_x + spriteWidth - 100;
		my_rect->x2 = my_x + spriteWidth - 20;
	}
}

void Rockstar::Melee(){
	if(flipped)
		playerHazards.push_back(new KillSquare(my_rect->x2, my_rect->y1 - 10, my_rect->x2 + 20, my_rect->y2 + 10, 0.5f, this));
}