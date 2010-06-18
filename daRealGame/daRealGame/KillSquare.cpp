#include "KillSquare.h"

KillSquare::KillSquare(float x1, float y1, float x2, float y2, float life, Character* owner)
{
	my_life = life;
	my_owner = owner;

	my_rect->x1 = x1;
	my_rect->x2 = x2;
	my_rect->y1 = y1;
	my_rect->y2 = y2;
}

KillSquare::~KillSquare(void)
{

}

bool KillSquare::Update(float &dt){
	my_life -= dt;
	if(my_life <= 0)
		return false;
	else
		return true;
}