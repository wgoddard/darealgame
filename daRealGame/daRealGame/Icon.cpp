#include "Icon.h"

Icon::Icon(HTEXTURE tex, Playable *player, hgeFont *font)
{
	my_player = player;

	int charType = player->getCharacterType();

	my_sprite = new hgeSprite(tex, 250.0f*charType, 0.0f, 250.0f, 140.0f);
	my_font = font;

	myQuad = new hgeQuad();

	for(int i = 0; i < 4; i++){
		myQuad->v[i].col = 0xFFFF0000;
	}
}

Icon::~Icon(void)
{
	delete my_sprite;
	delete myQuad;
}

void Icon::Update(float &dt){
	//do nothing? :S
}

void Icon::Render(float x, float y){
	float hpPer = 0.5f;

	myQuad->v[0].x = x + 84; myQuad->v[0].y = y + 44;
	myQuad->v[1].x = x + 94; myQuad->v[1].y = y + 60;
	myQuad->v[2].x = x + 84 + (hpPer*116); myQuad->v[2].y = y + 44;
	myQuad->v[3].x = x + 94 + (hpPer*90); myQuad->v[3].y = y + 60;

	hge->Gfx_RenderQuad(myQuad);
	my_sprite->Render(x, y);
	my_font->Render(x+141, y+42, HGETEXT_CENTER, "0/100");
}
