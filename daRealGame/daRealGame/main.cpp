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

hgeFont* mainFont;

bool FrameFunc();
bool RenderFunc();

bool FrameFunc()
{
	float dt=hge->Timer_GetDelta();

	if(hge->Input_GetKeyState(HGEK_ESCAPE)){
		return true;
	}

	return false;
}


bool RenderFunc()
{
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(0);

	mainFont->printf(5, 5, HGETEXT_LEFT, "dt:%.3f\nFPS:%d", hge->Timer_GetDelta(), hge->Timer_GetFPS());

	hge->Gfx_EndScene();

	return false;
}


//int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
int main (int argc, char * argv[])
{
	hge = hgeCreate(HGE_VERSION);

	hge->System_SetState(HGE_LOGFILE, "hq2.log");
	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
	hge->System_SetState(HGE_TITLE, "Heart Quakers 2");
	hge->System_SetState(HGE_FPS, 100);
	hge->System_SetState(HGE_WINDOWED, S_WINDOWED);
	hge->System_SetState(HGE_SCREENWIDTH, S_WIDTH);
	hge->System_SetState(HGE_SCREENHEIGHT, S_HEIGHT);
	hge->System_SetState(HGE_SCREENBPP, S_BPP);
	hge->System_SetState(HGE_SHOWSPLASH, false);
	hge->System_SetState(HGE_ZBUFFER, true);

	if(hge->System_Initiate()) 
	{
		mainFont = new hgeFont("data/fonts/Segoe_Script_20.fnt");

		//Get things rolling.
		hge->System_Start();
	}

	// Clean up and shutdown

	delete mainFont;

	hge->System_Shutdown();
	hge->Release();

	_CrtDumpMemoryLeaks();

	return 0;
}
