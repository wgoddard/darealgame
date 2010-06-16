#include "World.h"


namespace Prominence { 

	World::World()
	{

		m_LevelIndex = 0;
		m_WorldFile = "";


		m_CurrentLevel = new Level();
	}

	World::~World(void)
	{
		delete m_CurrentLevel;
	}

	void World::NextLevel()
	{
		Level * nextLevel = new Level();

		if (nextLevel->LoadXML(m_WorldFile, m_LevelIndex + 1) )
		{
			delete m_CurrentLevel;
			m_CurrentLevel = nextLevel;
		}
		else
		{
			delete nextLevel;
		}
	}

	void World::Update(Uint32 dt)
	{
		m_CurrentLevel->Update(dt);
	}

	void World::Render()
	{
		m_CurrentLevel->Render();
	}

	b2Body * World::CreateBody(b2PolygonDef * polyDef, float x, float y)
	{
		return m_CurrentLevel->CreateBody(polyDef, x, y);
	}

}
