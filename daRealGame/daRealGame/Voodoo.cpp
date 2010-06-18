#include "Voodoo.h"

Voodoo::Voodoo(HTEXTURE tex, Input *mIn) : Playable(tex, mIn)
{
	characterType = 3;

	my_max_health = (int)(my_max_health * 1.5);
	my_health = my_max_health;

	spriteWidth = 128;
	spriteHeight = 128;

	my_x = 400;

	//enum States { IDLE, WALK, MELEE, RANGED, SPECIAL, DEATH, VICTORY, EXTRA };
	
	my_frames[IDLE] = 2;
	my_frames[WALK] = 4;
	my_frames[MELEE] = 8;
	my_fp_sec[MELEE] = 0.1f;
	my_frames[RANGED] = 5;
	my_frames[SPECIAL] = 8;
	my_frames[DEATH] = 5;
	my_frames[VICTORY] = 4;

}

Voodoo::~Voodoo(void)
{
}

void Voodoo::Update(float &dt, float rel_x_speed){
	Playable::Update(dt, rel_x_speed);

	my_rect->y1 = my_y + spriteHeight - 20;
	my_rect->y2 = my_y + spriteHeight;
	my_rect->x1 = my_x + 10;
	my_rect->x2 = my_x + spriteWidth - 10;
}

void Voodoo::Melee(){
	playerHazards.push_back(new KillSquare(my_rect->x2, my_rect->y1 - 10, my_rect->x2 + 20, my_rect->y2 + 10, 0.5f, this));
	playerHazards.push_back(new KillSquare(my_rect->x1 - 20, my_rect->y1 - 10, my_rect->x1, my_rect->y2 + 10, 0.5f, this));
}
