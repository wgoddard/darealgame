#pragma once

#include "Global.h"
#include "tinyxml.h"
#include "Box2d.h"

#include <vector>

namespace Prominence {

	class Level
	{
	private:
		//std::vector<Entity*> m_Entities;
		std::string m_Name;
		b2World * m_b2World;
		b2Body* body;
	public:
		Level();
		~Level(void);
		void Update(Uint32 dt);
		void Render();
		void DrawBoxes();
		//void AddEntity(Entity * e) { m_Entities.push_back(e); }
		bool LoadXML(std::string file, int index);
		b2Body * CreateBody(b2PolygonDef * polyDef, float x, float y);
	};

}