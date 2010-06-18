#include "Playable.h"

Playable::Playable(HTEXTURE tex, Input *mIn) : Character(tex)
{
	characterType = 0;
	my_state = IDLE;

	my_input = mIn;
	numKills = 0;

	secTimer = 0.0f;
}

Playable::~Playable(void)
{
	
}

void Playable::Update(float &dt, float rel_x_speed){
	States opening = my_state;

	Character::Update(dt, rel_x_speed);

	my_input->update();

	if(secTimer > 0){
		secTimer -= dt;
	}

	if(my_state == IDLE || my_state == WALK){
		if(my_input->GetA()){
			my_state = MELEE;
			Melee();
		} else if(my_input->GetB()){
			my_state = RANGED;
		} else if(my_input->GetC()){
			my_state = SPECIAL;
		} else if(my_input->GetD()){
			my_state = DEATH;
		}
	}

	if(my_state == IDLE || my_state == WALK){
		double moveX = my_input->GetX();
		double moveY = my_input->GetY();

		double aimX = my_input->AimX();
		double aimY = my_input->AimY();

		my_x += my_hspeed * (float)my_input->GetX() * dt;
		my_y += my_vspeed * (float)my_input->GetY() * dt;

		if(aimX < 0)
			flipped = false;
		if(aimX > 0)
			flipped = true;

		if(moveX != 0 || moveY != 0){
			my_state = WALK;
		} else {
			my_state = IDLE;
		}
	}

	if(my_x < -128){
		if(secTimer <= 0){
			my_health--;
			secTimer = 1.0f;
		}
	} else if(my_x > 1280 - spriteWidth){
		my_x = 1280.0f - spriteWidth;
	}
	if(my_y < 120) {
		my_y = 120.0f;
	} if(my_y > 720-spriteHeight) {
		my_y = 720.0f-spriteHeight;
	}

	if(my_state != opening){
		cFrame = 0;
	}
}