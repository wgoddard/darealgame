#include "Character.h"

Character::Character(b2Body * body, HTEXTURE tex) : GfxObject(body, tex)
{

}

Character::~Character(void)
{

}

void Character::hit(Character &other, int damage){
	if(damage < my_health){
		int giveScore = (int)((my_health - damage) / my_max_health * my_given_kill_score);
		other.addScore(giveScore);
		my_score -= my_given_kill_score;
		my_health -= damage;
	} else {
		other.addScore((int)(my_health / (my_max_health) * my_given_kill_score));
		my_health = 0.0f;
	}
}