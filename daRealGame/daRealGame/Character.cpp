#include "Character.h"

Character::Character(HTEXTURE tex) {
	my_max_health = 10;
	my_health = my_max_health;
	my_attack_speed = 3;
	my_ranged_speed = 2;
	my_hspeed = 200;
	my_vspeed = 150;

	my_x = 0;
	my_y = 0;

	int my_frames[] = {2, 2, 2, 2, 2, 2, 2, 2};
	int my_fps[] =    {2, 2, 2, 2, 2, 2, 2, 2};

	my_sprite = new hgeSprite(tex, 0, 0, 128, 128);
}

Character::~Character(void) {
	delete my_sprite;
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

void Character::Update(float &dt, float rel_x_speed){
	my_x += rel_x_speed;
}

void Character::Render(){
	my_sprite->Render(my_x, my_y);
}