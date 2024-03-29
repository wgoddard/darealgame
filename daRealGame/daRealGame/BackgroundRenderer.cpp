#include "BackgroundRenderer.h"

BackgroundRenderer::BackgroundRenderer(void){
	currentScrollPos = 0.0f;
	currentTile = 0;
	dscroll = 0.0f;
}

BackgroundRenderer::~BackgroundRenderer(void){
	while(tiles.size() > 0){
		//TODO
		//hge->Texture_Free(tiles[0]->tex);
		delete tiles[0];
		tiles.erase(tiles.begin(), tiles.begin()+1);
	}
}

void BackgroundRenderer::update(float &dt){
	currentScrollPos += (dscroll*dt);

	if(1024*tiles.size() + currentScrollPos < 1300){
		loadTile(tiles.size());
	}
}

void BackgroundRenderer::render(){
	for(int i=0; i<(int)tiles.size(); i++){
		tiles[i]->Render((float)(int)(1022.0f*i + currentScrollPos), 0.0f);
	}
}

void BackgroundRenderer::loadTile(int x){
	std::stringstream out;

	out << "data/regions/Tile_";

	if(x < 10){
		out << "00" << x;
	} else if(x < 100) {
		out << "0" << x;
	} else {
		out << x;
	}

	out << ".png";

	std::string s = out.str();

	HTEXTURE blah = hge->Texture_Load(s.data());

	hgeSprite *tempSprite = new hgeSprite(blah, 1, 1, 1022, 720);
	tempSprite->SetZ(1.0);

	tiles.push_back(tempSprite);
}