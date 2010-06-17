#include "Playable.h"

Playable::Playable(HTEXTURE tex, Input *mIn) : Character(tex)
{
	characterType = 0;
	my_state = IDLE;

	my_input = mIn;
	numKills = 0;
}

Playable::~Playable(void)
{
	
}

void Playable::Update(float &dt, float rel_x_speed){
	Character::Update(dt, rel_x_speed);

	my_input->update();

	my_x += my_hspeed * my_input->GetX() * dt;
	my_y += my_vspeed * my_input->GetY() * dt;
}