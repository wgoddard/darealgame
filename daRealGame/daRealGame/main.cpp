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
#include "BackgroundRenderer.h"
#include "Icon.h"

#include "Janitor.h"
#include "Ninja.h"
#include "Rockstar.h"
#include "Voodoo.h"

// Pointer to the HGE interface.
HGE *hge=0;

hgeFont* mainFont;
hgeFont* statFont;

BackgroundRenderer *bg;
std::vector<Icon*> icons;
std::vector<Playable*> players;
std::vector<Input*> controllers;

HTEXTURE iconsTex;

bool FrameFunc();
bool RenderFunc();

bool FrameFunc()
{
	float dt=hge->Timer_GetDelta();

	bg->update(dt);

	if(hge->Input_GetKeyState(HGEK_ESCAPE)){
		return true;
	}

	return false;
}


bool RenderFunc()
{
	int i = 0;

	hge->Gfx_BeginScene();

	//Fullscreen redrawing
	//hge->Gfx_Clear(0);

	bg->render();

	for(i = 0; i<(int)icons.size(); i++){
		icons[i]->Render(250.0f*i, 20);
	}

	mainFont->printf(1, 1, HGETEXT_LEFT, "FPS:%d", hge->Timer_GetFPS());

	hge->Gfx_EndScene();

	return false;
}


//int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
int main (int argc, char * argv[])
{
	controllers.push_back(new Keyboard());
	controllers.push_back(new Controller(0));
	controllers.push_back(new Controller(1));
	controllers.push_back(new Controller(2));
	controllers.push_back(new Controller(3));

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
		bg = new BackgroundRenderer();
		mainFont = new hgeFont("data/fonts/Interfaces.fnt");
		statFont = new hgeFont("data/fonts/Numbers.fnt");

		iconsTex = hge->Texture_Load("data/characters/Icons.png");

		players.push_back(new Janitor(0, iconsTex, controllers[0]));
		players.push_back(new Rockstar(0, iconsTex, controllers[1]));
		players.push_back(new Ninja(0, iconsTex, controllers[2]));
		players.push_back(new Voodoo(0, iconsTex, controllers[3]));

		icons.push_back(new Icon(iconsTex, players[0], statFont));
		icons.push_back(new Icon(iconsTex, players[1], statFont));
		icons.push_back(new Icon(iconsTex, players[2], statFont));
		icons.push_back(new Icon(iconsTex, players[3], statFont));

		//Get things rolling.
		hge->System_Start();
	}

	// Clean up and shutdown

	int i = 0;

	for(i=0; i<(int)icons.size(); i++){
		delete icons[i];
	}

	for(i=0; i<(int)players.size(); i++){
		delete players[i];
	}

	for(i=0; i<(int)controllers.size(); i++){
		delete controllers[i];
	}

	icons.clear();
	players.clear();
	controllers.clear();

	delete mainFont;
	delete statFont;
	delete bg;

	hge->System_Shutdown();
	hge->Release();


	//Memory leak from vectors :(
	_CrtDumpMemoryLeaks();

	return 0;
}
