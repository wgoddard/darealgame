#include "BackgroundRenderer.h"

BackgroundRenderer::BackgroundRenderer(void){
	currentScrollPos = 0.0f;
	currentTile = 0;
	dscroll = -50.0f;
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

	std::cout << 1024*tiles.size() + currentScrollPos << " & " << 1300 << std::endl;

	if(1024*tiles.size() + currentScrollPos < 1300){
		loadTile(tiles.size());
	}
}

void BackgroundRenderer::render(){
	for(int i=0; i<(int)tiles.size(); i++){
		tiles[i]->Render(1024.0f*i + currentScrollPos, 0.0f);
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

	hgeSprite *tempSprite = new hgeSprite(blah, 0, 0, 1024, 720);

	tiles.push_back(tempSprite);
}