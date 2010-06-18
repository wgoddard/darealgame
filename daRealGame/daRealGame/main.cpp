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
#include "KillSquare.h"

#include "Janitor.h"
#include "Ninja.h"
#include "Rockstar.h"
#include "Voodoo.h"

#include "Boxer.h"

// Pointer to the HGE interface.
HGE *hge=0;

hgeFont* mainFont;
hgeFont* statFont;

BackgroundRenderer *bg;
std::vector<Icon*> icons;
std::vector<Playable*> players;
std::vector<AICharacter*> enemies;
std::vector<Input*> controllers;

//std::vector<KillSquare*> enemyHazards;
std::vector<KillSquare*> playerHazards;

float mapSpeed = -20.0f;

HTEXTURE iconsTex;

HTEXTURE rockstarTex;
HTEXTURE ninjaTex;
HTEXTURE voodooTex;
HTEXTURE janitorTex;

HTEXTURE boxerTex;

bool FrameFunc();
bool RenderFunc();

bool FrameFunc()
{
	float dt=hge->Timer_GetDelta();

	bg->update(dt);

	float map_speed = bg->getSpeed() * dt;

	if(hge->Input_GetKeyState(HGEK_ESCAPE)){
		return true;
	}

	int i = 0;

	//Update players
	for(i = 0; i<(int)players.size(); i++){
		players[i]->Update(dt, map_speed);

		if(!players[i]->isAlive()){
			controllers.push_back(players[i]->getInput());
			delete players[i];
			delete icons[i];
			players.erase(players.begin()+i, players.begin()+i+1);
			icons.erase(icons.begin()+i, icons.begin()+i+1);

			if(players.size() == 0){
				mapSpeed = bg->getSpeed();
				bg->setSpeed(0.0f);
			}
		}
	}

	//Update enemies
	for(i = 0; i<(int)enemies.size(); i++){
		enemies[i]->Update(dt, map_speed);

		if(!enemies[i]->isAlive()){
			delete enemies[i];
			enemies.erase(enemies.begin()+i, enemies.begin()+i+1);
		}
	}

	//Collision Detection
	for(i = 0; i<(int)playerHazards.size(); i++){
		if(playerHazards[i]->Update(dt)){
			int j = 0;
			for(j = 0; j<(int)enemies.size(); j++){
				if(playerHazards[i]->doesCollide(*enemies[j])){
					std::cout << "Hit @ " << enemies[j]->getHealth() << " / " << enemies[j]->getMaxHealth() << "\n";
					enemies[j]->hit(playerHazards[i]->getOwner(), 5);
				}
			}
		} else {
			delete playerHazards[i];
			playerHazards.erase(playerHazards.begin()+i, playerHazards.begin()+i+1);
		}
	}

	for(i=0; i < (int)controllers.size(); i++){
		controllers[i]->update();

		if(i==0){
			std::cout << controllers[0]->GetA() << " " << controllers[0]->GetB() << " " << controllers[0]->GetC() << " " << controllers[0]->GetD() << std::endl;
		}

		if(controllers[i]->GetA()){
			players.push_back(new Voodoo(voodooTex, controllers[i]));
			icons.push_back(new Icon(iconsTex, players[players.size()-1], statFont));
			controllers.erase(controllers.begin()+i, controllers.begin()+i+1);

			bg->setSpeed(mapSpeed);
		} else if(controllers[i]->GetB()){
			players.push_back(new Rockstar(rockstarTex, controllers[i]));
			icons.push_back(new Icon(iconsTex, players[players.size()-1], statFont));
			controllers.erase(controllers.begin()+i, controllers.begin()+i+1);

			bg->setSpeed(mapSpeed);
		} else if(controllers[i]->GetC()){
			players.push_back(new Janitor(janitorTex, controllers[i]));
			icons.push_back(new Icon(iconsTex, players[players.size()-1], statFont));
			controllers.erase(controllers.begin()+i, controllers.begin()+i+1);

			bg->setSpeed(mapSpeed);
		} else if(controllers[i]->GetD()){
			players.push_back(new Ninja(ninjaTex, controllers[i]));
			icons.push_back(new Icon(iconsTex, players[players.size()-1], statFont));
			controllers.erase(controllers.begin()+i, controllers.begin()+i+1);

			bg->setSpeed(mapSpeed);
		}
	}

	return false;
}


bool RenderFunc()
{
	int i = 0;

	hge->Gfx_BeginScene();


	//Fullscreen redrawing
	hge->Gfx_Clear(0);

	bg->render();

	for(i = 0; i<(int)players.size(); i++){
		players[i]->Render();

		hgeRect *drawRect = players[i]->getHitRect();

		hge->Gfx_RenderLine(drawRect->x1, drawRect->y1,drawRect->x2, drawRect->y1, 0xFFFF0000, 1.0);
		hge->Gfx_RenderLine(drawRect->x2, drawRect->y1,drawRect->x2, drawRect->y2, 0xFFFF0000, 1.0);
		hge->Gfx_RenderLine(drawRect->x1, drawRect->y2,drawRect->x2, drawRect->y2, 0xFFFF0000, 1.0);
		hge->Gfx_RenderLine(drawRect->x1, drawRect->y1,drawRect->x1, drawRect->y2, 0xFFFF0000, 1.0);
	}

	for(i = 0; i<(int)enemies.size(); i++){
		enemies[i]->Render();

		hgeRect *drawRect = enemies[i]->getHitRect();

		hge->Gfx_RenderLine(drawRect->x1, drawRect->y1,drawRect->x2, drawRect->y1, 0xFFFF0000, 1.0);
		hge->Gfx_RenderLine(drawRect->x2, drawRect->y1,drawRect->x2, drawRect->y2, 0xFFFF0000, 1.0);
		hge->Gfx_RenderLine(drawRect->x1, drawRect->y2,drawRect->x2, drawRect->y2, 0xFFFF0000, 1.0);
		hge->Gfx_RenderLine(drawRect->x1, drawRect->y1,drawRect->x1, drawRect->y2, 0xFFFF0000, 1.0);
	}

	for(i = 0; i<(int)playerHazards.size(); i++){
		hgeRect *drawRect = playerHazards[i]->getHitRect();

		hge->Gfx_RenderLine(drawRect->x1, drawRect->y1,drawRect->x2, drawRect->y1, 0xFFFF0000, 1.0);
		hge->Gfx_RenderLine(drawRect->x2, drawRect->y1,drawRect->x2, drawRect->y2, 0xFFFF0000, 1.0);
		hge->Gfx_RenderLine(drawRect->x1, drawRect->y2,drawRect->x2, drawRect->y2, 0xFFFF0000, 1.0);
		hge->Gfx_RenderLine(drawRect->x1, drawRect->y1,drawRect->x1, drawRect->y2, 0xFFFF0000, 1.0);
	}

	for(i = 0; i<(int)icons.size(); i++){
		icons[i]->Render(250.0f*i, 20);
	}

	mainFont->printf(1, 1, HGETEXT_LEFT, "FPS:%d", hge->Timer_GetFPS());

	if(players.size() == 0){
		mainFont->printf(1280/2, 720/2, HGETEXT_CENTER, "Press Enter Or Start to Play.");
	}

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
	hge->System_SetState(HGE_TITLE, "Real HQ");
	//hge->System_SetState(HGE_FPS, 100);
	hge->System_SetState(HGE_WINDOWED, S_WINDOWED);
	hge->System_SetState(HGE_SCREENWIDTH, S_WIDTH);
	hge->System_SetState(HGE_SCREENHEIGHT, S_HEIGHT);
	hge->System_SetState(HGE_SCREENBPP, S_BPP);
	hge->System_SetState(HGE_SHOWSPLASH, false);
	hge->System_SetState(HGE_ZBUFFER, true);

	if(hge->System_Initiate()) 
	{
		bg = new BackgroundRenderer();
		//bg->setSpeed(mapSpeed);

		mainFont = new hgeFont("data/fonts/Interfaces.fnt");
		statFont = new hgeFont("data/fonts/Numbers.fnt");

		mainFont->SetZ(0.0);
		statFont->SetZ(0.0);

		iconsTex = hge->Texture_Load("data/characters/Players/Icons.png");
		
		rockstarTex = hge->Texture_Load("data/characters/Players/Rockstar.png");
		ninjaTex = hge->Texture_Load("data/characters/Players/Ninja.png");
		voodooTex = hge->Texture_Load("data/characters/Players/Voodoo.png");
		janitorTex = hge->Texture_Load("data/characters/Players/Blank.png");

		boxerTex = hge->Texture_Load("data/characters/enemies/Boxer.png");

		enemies.push_back(new Boxer(boxerTex));
		enemies[0]->move(700, 300);

		//Get things rolling.
		hge->System_Start();
	}

	// Clean up and shutdown

	int i = 0;

	for(i=0; i<(int)icons.size(); i++){
		delete icons[i];
	}

	for(i=0; i<(int)players.size(); i++){
		controllers.push_back(players[i]->getInput());
		delete players[i];
	}

	for(i=0; i<(int)enemies.size(); i++){
		delete enemies[i];
	}

	for(i=0; i<(int)controllers.size(); i++){
		delete controllers[i];
	}

	icons.clear();
	players.clear();
	enemies.clear();
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
