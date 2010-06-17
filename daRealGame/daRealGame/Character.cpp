#include "Character.h"

Character::Character(HTEXTURE tex) : GfxObject(tex) {
	my_max_health = 10;
	my_health = my_max_health;
	my_attack_speed = 3;
	my_ranged_speed = 2;
	my_hspeed = 10;
	my_vspeed = 10;
}

Character::~Character(void) {
	
}

void Character::hit(Character &other, int damage) {
	if(damage < my_health) {
		int giveScore = (int)((my_health - damage) / my_max_health * my_given_kill_score);
		other.addScore(giveScore);
		my_score -= my_given_kill_score;
		my_health -= damage;
	} else {
		other.addScore((int)(my_health / (my_max_health) * my_given_kill_score));
		my_health = 0;
	}
}

void Character::Update(float &dt){

}

void Character::Render(){
	//if(my_sprite != 0)
		//my_sprite->Render(my_x, my_y);
}