#include "Character.h"

Character::Character(HTEXTURE tex) : Collidable() 
{
	my_max_health = 10;
	my_health = my_max_health;
	my_attack_speed = 3;
	my_ranged_speed = 2;
	my_hspeed = 200;
	my_vspeed = 150;

	my_x = 0;
	my_y = 0;

	spriteWidth = 128;
	spriteHeight = 128;

	my_state = IDLE;

	flipped = true;
	cFrame = 0;

	my_alive = true;

	my_frames[IDLE] = 0;
	my_fp_sec[IDLE] = 0.1f;
	my_frames[WALK] = 0;
	my_fp_sec[WALK] = 0.2f;
	my_frames[MELEE] = 0;
	my_fp_sec[MELEE] = 0.2f;
	my_frames[RANGED] = 0;
	my_fp_sec[RANGED] = 0.2f;
	my_frames[SPECIAL] = 0;
	my_fp_sec[SPECIAL] = 0.2f;
	my_frames[DEATH] = 0;
	my_fp_sec[DEATH] = 0.2f;
	my_frames[VICTORY] = 0;
	my_fp_sec[VICTORY] = 0.2f;
	my_frames[EXTRA] = 0;
	my_fp_sec[EXTRA] = 0.2f;

	my_sprite = new hgeSprite(tex, 0, 0, 128, 128);
	
	frameTimer = 0;
}

Character::~Character(void) {
	delete my_sprite;
}

void Character::hit(Character *other, int damage) {
	if(damage < my_health) {
		int giveScore = (int)((my_health - damage) / my_max_health * my_given_kill_score);
		other->addScore(giveScore);
		my_score -= my_given_kill_score;
		my_health -= damage;
	} else {
		other->addScore((int)(my_health / (my_max_health) * my_given_kill_score));
		my_health = 0;
	}
}

void Character::Update(float &dt, float rel_x_speed){
	my_x += rel_x_speed;

	frameTimer += dt;

	if(my_health <= 0 && my_state != DEATH){
		my_health = 0;
		my_state = DEATH;
		cFrame = 0;
	}

	while(frameTimer > my_fp_sec[my_state]){
		cFrame++;
		frameTimer -= my_fp_sec[my_state];
	}

	if(cFrame >= my_frames[my_state]){
		if(my_state == DEATH)
			my_alive = false;
		if(my_state != IDLE && my_state != WALK){
			my_state = IDLE;
		}
		cFrame = 0;
	}

	my_sprite->SetTextureRect((float)cFrame * spriteWidth, (float)spriteHeight * my_state, (float)spriteWidth, (float)spriteHeight);

	my_sprite->SetZ(1 - (my_y / 720));
}

void Character::Render(){
	if(flipped) {
		my_sprite->RenderEx(my_x+spriteWidth, my_y, 0.0f, -1.0f, 1.0f);
	} else {
		my_sprite->RenderEx(my_x, my_y, 0.0f, 1.0f, 1.0f);
	}
}