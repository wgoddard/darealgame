#pragma once
#include "collidable.h"
#include "Character.h"

class KillSquare :
	public Collidable
{
protected:
	float my_life;
	Character* my_owner;
public:
	KillSquare(float x1, float y1, float x2, float y2, float life, Character* owner);
	~KillSquare(void);
	bool Update(float &dt);

	Character* getOwner(){ return my_owner; }
};
