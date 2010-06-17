#pragma once

#include <vector>
#include <sstream>
#include <string>
#include "hge.h"
#include "hgeSprite.h"

#include <iostream>

extern HGE *hge;

class BackgroundRenderer
{
protected:
	float currentScrollPos;
	int currentTile;
	float dscroll;

	std::vector<hgeSprite*> tiles;

	void loadTile(int x);
public:
	BackgroundRenderer(void);
	~BackgroundRenderer(void);

	void update(float &dt);
	void render();

	void setSpeed(float newSpeed){ currentScrollPos = newSpeed; }
	float getSpeed(){ return currentScrollPos; }
};
