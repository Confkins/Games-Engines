#pragma once
#include "Game.h"
#include "PhysicsController.h"
#include "PhysicsFactory.h"
#include <btBulletDynamicsCommon.h>

namespace BGE
{
	class Assignment :
		public Game
	{
	private:

	public:
		Assignment(void);
		~Assignment(void);
		bool Initialise();
		void Update();
		void Cleanup();
		void CreateWall();
		shared_ptr<PhysicsController> bird;
		shared_ptr<PhysicsController> CreateCaterpiller(glm::vec3 position, float scale = 5);
		//shared_ptr<PhysicsController> CreateCaterpiller2(glm::vec3 position);
	};
}