#pragma once

#include "Global.h"
#include "Box2d.h"
#include "Level.h"

namespace Prominence {

	class World
	{
	private:
		//***Replace with HGE renderer
		//Renderer & m_Renderer;

		//Vector of Levels or level defs or such
		Level * m_CurrentLevel;
		std::string m_WorldFile;
		int m_LevelIndex;
	public:
		World();
		~World(void);

		void SetWorldFile(std::string file) { m_WorldFile = file; }
		void NextLevel();

		void Update(Uint32 dt);
		void Render();
		//Quad GetBody();
		b2Body * CreateBody(b2PolygonDef * polyDef, float x, float y);


		//Entity * CreateEntity(Sprite * sprite, float x, float y);
		//AnimatedEntity * World::CreateAnimatedEntity(AnimatedSprite * sprite, float x, float y);
		//Actor * World::CreateActor(AnimatedSprite * sprite, float x, float y);
		//IsoActor * World::CreateIsoActor(AnimatedSprite * sprite, float x, float y);

	};

}