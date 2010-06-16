/*
*
*   
*
*/

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#include <iostream>
#include <vector>

#include "hge.h"
#include "hgesprite.h"
#include "hgeanim.h"
#include "hgefont.h"
#include "hgeparticle.h"

#include "global.h"
#include "Input.h"
#include "Controller.h"
#include "Keyboard.h"

// Pointer to the HGE interface.
HGE *hge=0;

bool FrameFunc();
bool RenderFunc();

std::vector<Input*> controllers;

bool FrameFunc()
{
	float dt=hge->Timer_GetDelta();

	if(hge->Input_GetKeyState(HGEK_ESCAPE)){
		return true;
	}

	for(int i=0; i<(int)controllers.size(); i++){
		controllers[i]->update();
		std::cout << controllers[i]->GetA() << "; " 
					<< controllers[i]->GetB() << "; " 
					<< controllers[i]->GetC() << "; " 
					<< controllers[i]->GetD() << "; " 
					<< controllers[i]->GetX() << "; "
					<< controllers[i]->GetY() << "; "
					<< controllers[i]->AimX() << "; "
					<< controllers[i]->AimY() << "\n";
	}

	return false;
}


bool RenderFunc()
{
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(0);

	//mainFont->printf(5, 5, HGETEXT_LEFT, "dt:%.3f\nFPS:%d", hge->Timer_GetDelta(), hge->Timer_GetFPS());

	hge->Gfx_EndScene();

	return false;
}


//int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
int main (int argc, char * argv[])
{

	controllers.push_back(new Controller(0));
	controllers.push_back(new Keyboard());

	hge = hgeCreate(HGE_VERSION);

	hge->System_SetState(HGE_LOGFILE, "dagame.log");
	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
	hge->System_SetState(HGE_TITLE, "Da Game");
	hge->System_SetState(HGE_FPS, 100);
	hge->System_SetState(HGE_WINDOWED, S_WINDOWED);
	hge->System_SetState(HGE_SCREENWIDTH, S_WIDTH);
	hge->System_SetState(HGE_SCREENHEIGHT, S_HEIGHT);
	hge->System_SetState(HGE_SCREENBPP, S_BPP);
	hge->System_SetState(HGE_SHOWSPLASH, false);
	hge->System_SetState(HGE_ZBUFFER, true);

	if(hge->System_Initiate()) 
	{
		//Get things rolling.
		hge->System_Start();
	}

	// Clean up and shutdown

	hge->System_Shutdown();
	hge->Release();

	while(controllers.size() > 0){
		delete controllers[0];
		controllers.erase(controllers.begin(), controllers.begin()+1);
	}

	if(_CrtDumpMemoryLeaks()){
		//Leaks :(
	} else {
		//No Leaks :)
	}

	return 0;
}
