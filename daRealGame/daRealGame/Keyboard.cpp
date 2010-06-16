#include "Keyboard.h"

Keyboard::Keyboard(void)
{

}

Keyboard::~Keyboard(void)
{
	
}

void Keyboard::update(){
	if(hge->Input_GetKeyState(HGEK_LEFT) || hge->Input_GetKeyState(HGEK_A)){
		dx = -1.0;
	} else if(hge->Input_GetKeyState(HGEK_RIGHT) || hge->Input_GetKeyState(HGEK_D)){
		dx = 1.0;
	} else {
		dx = 0.0;
	}
	
	if(hge->Input_GetKeyState(HGEK_UP) || hge->Input_GetKeyState(HGEK_W)){
		dy = -1.0;
	} else if(hge->Input_GetKeyState(HGEK_DOWN) || hge->Input_GetKeyState(HGEK_S)){
		dy = 1.0;
	} else {
		dy = 0.0;
	}

	stateA = (hge->Input_GetKeyState(HGEK_H) || hge->Input_GetKeyState(HGEK_Z));
	stateB = (hge->Input_GetKeyState(HGEK_J) || hge->Input_GetKeyState(HGEK_X));
	stateC = (hge->Input_GetKeyState(HGEK_K) || hge->Input_GetKeyState(HGEK_C));
	stateD = (hge->Input_GetKeyState(HGEK_L) || hge->Input_GetKeyState(HGEK_V));

	ax = dx;
	ay = dy;
}

void Keyboard::rumble(){
	//Bwahaha... Can't vibrate a keyboard
}