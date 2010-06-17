#pragma once

#include "hgeSprite.h"
#include "hgeFont.h"
#include "hge.h"

#include "Playable.h"

extern HGE *hge;

class Icon
{
private:
	hgeSprite *my_sprite;
	Playable *my_player;
	hgeFont *my_font;
	hgeQuad *myQuad;
public:
	Icon(HTEXTURE tex, Playable *player, hgeFont *font);
	~Icon(void);

	void Update(float &dt);
	void Render(float x, float y);
};
