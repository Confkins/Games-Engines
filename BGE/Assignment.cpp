#include "PhysicsGame1.h"
#include "PhysicsController.h"
#include "Sphere.h"
#include "PhysicsCamera.h"
#include "Box.h"
#include "Cylinder.h"
#include "Steerable3DController.h"
#include "Ground.h"
#include "Content.h"
#include <btBulletDynamicsCommon.h>
#include <gtc/quaternion.hpp>
#include <gtx/quaternion.hpp>
#include <gtx/euler_angles.hpp>
#include <gtx/norm.hpp>
#include "VectorDrawer.h"
#include "Utils.h"
#include "PhysicsFactory.h"
#include "Game.h" 
#include "Model.h"
#include "dirent.h"
#include "Capsule.h" 

#include "Assignment.h"

using namespace BGE;

Assignment::Assignment(void)
{
}

Assignment::~Assignment(void)
{
}


bool Assignment::Initialise()
{
	physicsFactory->CreateGroundPhysics();
	physicsFactory->CreateCameraPhysics();
	dynamicsWorld->setGravity(btVector3(0, -30, 0));
	shared_ptr<PhysicsController> HappyCaterpiller = CreateCaterpiller(glm::vec3(0, 20, 0), 10);

	
	if (!Game::Initialise()) {
		return false;
	}



	return true;
}

void BGE::Assignment::Update()
{
	//cyl->rigidBody->applyTorque(GLToBtVector(glm::vec3(0.0f, 0.0f, 1.0f)));
	


	//Game::Update();
}

void BGE::Assignment::Cleanup()
{
	Game::Cleanup();
}

shared_ptr<PhysicsController> Assignment::CreateCaterpiller(glm::vec3 position, float scale)
{

	float head_rad = scale / 0.8;
	float diameter = scale * 2;
	float connectRad = 2.5;
	float connectLength = 5;
	float leg_length = 10;
	float leg_width = 3;

	glm::quat neck_rot = glm::angleAxis(90.0F, glm::vec3(1, 0, 0));
	glm::quat leg_yaw = glm::angleAxis(60.0F, glm::vec3(1, 0, 0));

	shared_ptr<PhysicsController> head = physicsFactory->CreateSphere(head_rad, position, glm::quat());
	shared_ptr<PhysicsController> bodySegment1 = physicsFactory->CreateSphere(scale, position + glm::vec3(0, 0, -head_rad - scale - 5), glm::quat());
	shared_ptr<PhysicsController> bodySegment2 = physicsFactory->CreateSphere(scale, position + glm::vec3(0, 0, -head_rad - (scale*2) - 10), glm::quat());
	shared_ptr<PhysicsController> bodySegment3 = physicsFactory->CreateSphere(scale, position + glm::vec3(0, 0, -head_rad - (scale*3) - 15), glm::quat());
	shared_ptr<PhysicsController> bodySegment4 = physicsFactory->CreateSphere(scale, position + glm::vec3(0, 0, -head_rad - (scale*4) - 20), glm::quat());
	shared_ptr<PhysicsController> bodySegment5 = physicsFactory->CreateSphere(scale, position + glm::vec3(0, 0, -head_rad - (scale*5) - 25), glm::quat());
	shared_ptr<PhysicsController> bodySegment6 = physicsFactory->CreateSphere(scale, position + glm::vec3(0, 0, -head_rad - (scale*6) - 30), glm::quat());
	shared_ptr<PhysicsController> bodySegment7 = physicsFactory->CreateSphere(scale, position + glm::vec3(0, 0, -head_rad - (scale*7) - 35), glm::quat());
	shared_ptr<PhysicsController> bodySegment8 = physicsFactory->CreateSphere(scale, position + glm::vec3(0, 0, -head_rad - (scale*8) - 40), glm::quat());
	shared_ptr<PhysicsController> bodySegment9 = physicsFactory->CreateSphere(scale, position + glm::vec3(0, 0, -head_rad - (scale*9) - 45), glm::quat());


	shared_ptr<PhysicsController> leg1 = physicsFactory->CreateBox(leg_width, leg_width, leg_length, glm::vec3(scale,scale-2,(-head_rad - scale - 5)), leg_yaw);
	shared_ptr<PhysicsController> leg2 = physicsFactory->CreateBox(leg_width, leg_width, leg_length, glm::vec3(-scale, scale - 2, (-head_rad - scale - 5)), leg_yaw);
	shared_ptr<PhysicsController> leg3 = physicsFactory->CreateBox(leg_width, leg_width, leg_length, glm::vec3(scale, scale - 2, (-head_rad - scale * 3 - 10)), leg_yaw);
	shared_ptr<PhysicsController> leg4 = physicsFactory->CreateBox(leg_width, leg_width, leg_length, glm::vec3(-scale, scale - 2, (-head_rad - scale * 3 - 10)), leg_yaw);
	shared_ptr<PhysicsController> leg5 = physicsFactory->CreateBox(leg_width, leg_width, leg_length, glm::vec3(scale, scale - 2, (-head_rad - scale * 5 - 15)), leg_yaw);
	shared_ptr<PhysicsController> leg6 = physicsFactory->CreateBox(leg_width, leg_width, leg_length, glm::vec3(-scale, scale - 2, (-head_rad - scale * 5 - 15)), leg_yaw);
	shared_ptr<PhysicsController> leg7 = physicsFactory->CreateBox(leg_width, leg_width, leg_length, glm::vec3(scale, scale - 2, (-head_rad - scale * 7 - 20)), leg_yaw);
	shared_ptr<PhysicsController> leg8 = physicsFactory->CreateBox(leg_width, leg_width, leg_length, glm::vec3(-scale, scale - 2, (-head_rad - scale * 7 - 20)), leg_yaw);
	shared_ptr<PhysicsController> leg9 = physicsFactory->CreateBox(leg_width, leg_width, leg_length, glm::vec3(scale, scale - 2, (-head_rad - scale * 9 - 25)), leg_yaw);
	shared_ptr<PhysicsController> leg10 = physicsFactory->CreateBox(leg_width, leg_width, leg_length, glm::vec3(-scale, scale - 2, (-head_rad - scale * 9 - 25)), leg_yaw);
	shared_ptr<PhysicsController> leg11 = physicsFactory->CreateBox(leg_width, leg_width, leg_length, glm::vec3(scale, scale - 2, (-head_rad - scale * 11 - 30)), leg_yaw);
	shared_ptr<PhysicsController> leg12 = physicsFactory->CreateBox(leg_width, leg_width, leg_length, glm::vec3(-scale, scale - 2, (-head_rad - scale * 11 - 30)), leg_yaw);
	shared_ptr<PhysicsController> leg13 = physicsFactory->CreateBox(leg_width, leg_width, leg_length, glm::vec3(scale, scale - 2, (-head_rad - scale * 13 - 35)), leg_yaw);
	shared_ptr<PhysicsController> leg14 = physicsFactory->CreateBox(leg_width, leg_width, leg_length, glm::vec3(-scale, scale - 2, (-head_rad - scale * 13 - 35)), leg_yaw);
	shared_ptr<PhysicsController> leg15 = physicsFactory->CreateBox(leg_width, leg_width, leg_length, glm::vec3(scale, scale - 2, (-head_rad - scale * 15 - 40)), leg_yaw);
	shared_ptr<PhysicsController> leg16 = physicsFactory->CreateBox(leg_width, leg_width, leg_length, glm::vec3(-scale, scale - 2, (-head_rad - scale * 15 - 40)), leg_yaw);
	shared_ptr<PhysicsController> leg17 = physicsFactory->CreateBox(leg_width, leg_width, leg_length, glm::vec3(scale, scale - 2, (-head_rad - scale * 17 - 45)), leg_yaw);
	shared_ptr<PhysicsController> leg18 = physicsFactory->CreateBox(leg_width, leg_width, leg_length, glm::vec3(-scale, scale - 2, (-head_rad - scale * 17 - 45)), leg_yaw);
	
	btTransform t1, t2;
	btTransform t3, t4;
	btTransform t5, t6;
	btTransform t7, t8;
	btTransform t9, t10;
	btTransform t11, t12;
	btTransform t13, t14;
	btTransform t15, t16;
	btTransform t17, t18;
	btTransform t19, t20;
	btTransform t21, t22;
	btTransform t23, t24;
	btTransform t25, t26;
	btTransform t27, t28;
	btTransform t29, t30;
	btTransform t31, t32;
	btTransform t33, t34;
	btTransform t35, t36;
	
	t1.setIdentity();
	t2.setIdentity();
	t3.setIdentity();
	t4.setIdentity();
	t5.setIdentity();
	t6.setIdentity();
	t7.setIdentity();
	t8.setIdentity();
	t9.setIdentity();
	t10.setIdentity();
	t11.setIdentity();
	t12.setIdentity();
	t13.setIdentity();
	t14.setIdentity();
	t15.setIdentity();
	t16.setIdentity();
	t17.setIdentity();
	t18.setIdentity();
	t19.setIdentity();
	t20.setIdentity();
	t21.setIdentity();
	t22.setIdentity();
	t23.setIdentity();
	t24.setIdentity();
	t25.setIdentity();
	t26.setIdentity();
	t27.setIdentity();
	t28.setIdentity();
	t29.setIdentity();
	t30.setIdentity();
	t31.setIdentity();
	t32.setIdentity();
	t33.setIdentity();
	t34.setIdentity();
	t35.setIdentity();
	t36.setIdentity();


	t1.setOrigin(btVector3(scale, scale - 2, (-head_rad - scale - 5)));
	t2.setOrigin(btVector3(scale, scale - 2, (-head_rad - scale - 5)));
	t3.setOrigin(btVector3(-scale, scale - 2, (-head_rad - scale - 5)));
	t4.setOrigin(btVector3(-scale, scale - 2, (-head_rad - scale - 5)));
	t5.setOrigin(btVector3(scale, scale - 2, (-head_rad - scale*3 - 10)));
	t6.setOrigin(btVector3(scale, scale - 2, (-head_rad - scale*3 - 10)));
	t7.setOrigin(btVector3(-scale, scale - 2, (-head_rad - scale*3 - 10)));
	t8.setOrigin(btVector3(-scale, scale - 2, (-head_rad - scale*3 - 10)));
	t9.setOrigin(btVector3(scale, scale - 2, (-head_rad - scale*5 - 15)));
	t10.setOrigin(btVector3(scale, scale - 2, (-head_rad - scale*5 - 15)));
	t11.setOrigin(btVector3(-scale, scale - 2, (-head_rad - scale*5 - 15)));
	t12.setOrigin(btVector3(-scale, scale - 2, (-head_rad - scale*5 - 15)));
	t13.setOrigin(btVector3(scale, scale - 2, (-head_rad - scale*7 - 20)));
	t14.setOrigin(btVector3(scale, scale - 2, (-head_rad - scale*7 - 20)));
	t15.setOrigin(btVector3(-scale, scale - 2, (-head_rad - scale*7 - 20)));
	t16.setOrigin(btVector3(-scale, scale - 2, (-head_rad - scale*7 - 20)));
	t17.setOrigin(btVector3(scale, scale - 2, (-head_rad - scale*9 - 25)));
	t18.setOrigin(btVector3(scale, scale - 2, (-head_rad - scale*9 - 25)));
	t19.setOrigin(btVector3(-scale, scale - 2, (-head_rad - scale*9 - 25)));
	t20.setOrigin(btVector3(-scale, scale - 2, (-head_rad - scale*9 - 25)));
	t21.setOrigin(btVector3(scale, scale - 2, (-head_rad - scale*11 - 30)));
	t22.setOrigin(btVector3(scale, scale - 2, (-head_rad - scale*11 - 30)));
	t23.setOrigin(btVector3(-scale, scale - 2, (-head_rad - scale*11 - 30)));
	t24.setOrigin(btVector3(-scale, scale - 2, (-head_rad - scale*11 - 30)));
	t25.setOrigin(btVector3(scale, scale - 2, (-head_rad - scale*13 - 35)));
	t26.setOrigin(btVector3(scale, scale - 2, (-head_rad - scale*13 - 35)));
	t27.setOrigin(btVector3(-scale, scale - 2, (-head_rad - scale*13 - 35)));
	t28.setOrigin(btVector3(-scale, scale - 2, (-head_rad - scale*13 - 35)));
	t29.setOrigin(btVector3(scale, scale - 2, (-head_rad - scale*15 - 40)));
	t30.setOrigin(btVector3(scale, scale - 2, (-head_rad - scale*15 - 40)));
	t31.setOrigin(btVector3(-scale, scale - 2, (-head_rad - scale*15 - 40)));
	t32.setOrigin(btVector3(-scale, scale - 2, (-head_rad - scale*15 - 40)));
	t33.setOrigin(btVector3(scale, scale - 2, (-head_rad - scale*17 - 45)));
	t34.setOrigin(btVector3(scale, scale - 2, (-head_rad - scale*17 - 45)));
	t35.setOrigin(btVector3(-scale, scale - 2, (-head_rad - scale*17 - 45)));
	t36.setOrigin(btVector3(-scale, scale - 2, (-head_rad - scale*17 - 45)));

	btFixedConstraint * shoulderR1 = new btFixedConstraint(*bodySegment1->rigidBody, *leg1->rigidBody, t1, t2);
	btFixedConstraint * shoulderL1 = new btFixedConstraint(*bodySegment1->rigidBody, *leg2->rigidBody, t3, t4);
	btFixedConstraint * shoulderR2 = new btFixedConstraint(*bodySegment2->rigidBody, *leg3->rigidBody, t5, t6);
	btFixedConstraint * shoulderL2 = new btFixedConstraint(*bodySegment2->rigidBody, *leg4->rigidBody, t7, t8);
	btFixedConstraint * shoulderR3 = new btFixedConstraint(*bodySegment3->rigidBody, *leg5->rigidBody, t9, t10);
	btFixedConstraint * shoulderL3 = new btFixedConstraint(*bodySegment3->rigidBody, *leg6->rigidBody, t11, t12);
	btFixedConstraint * shoulderR4 = new btFixedConstraint(*bodySegment4->rigidBody, *leg7->rigidBody, t13, t14);
	btFixedConstraint * shoulderL4 = new btFixedConstraint(*bodySegment4->rigidBody, *leg8->rigidBody, t15, t16);
	btFixedConstraint * shoulderR5 = new btFixedConstraint(*bodySegment5->rigidBody, *leg9->rigidBody, t17, t18);
	btFixedConstraint * shoulderL5 = new btFixedConstraint(*bodySegment5->rigidBody, *leg10->rigidBody, t19, t20);
	btFixedConstraint * shoulderR6 = new btFixedConstraint(*bodySegment6->rigidBody, *leg11->rigidBody, t21, t22);
	btFixedConstraint * shoulderL6 = new btFixedConstraint(*bodySegment6->rigidBody, *leg12->rigidBody, t23, t24);
	btFixedConstraint * shoulderR7 = new btFixedConstraint(*bodySegment7->rigidBody, *leg13->rigidBody, t25, t26);
	btFixedConstraint * shoulderL7 = new btFixedConstraint(*bodySegment7->rigidBody, *leg14->rigidBody, t27, t28);
	btFixedConstraint * shoulderR8 = new btFixedConstraint(*bodySegment8->rigidBody, *leg15->rigidBody, t29, t30);
	btFixedConstraint * shoulderL8 = new btFixedConstraint(*bodySegment8->rigidBody, *leg16->rigidBody, t31, t32);
	btFixedConstraint * shoulderR9 = new btFixedConstraint(*bodySegment9->rigidBody, *leg17->rigidBody, t33, t34);
	btFixedConstraint * shoulderL9 = new btFixedConstraint(*bodySegment9->rigidBody, *leg18->rigidBody, t35, t36);

	dynamicsWorld->addConstraint(shoulderR1);
	dynamicsWorld->addConstraint(shoulderL1);
	dynamicsWorld->addConstraint(shoulderR2);
	dynamicsWorld->addConstraint(shoulderL2);
	dynamicsWorld->addConstraint(shoulderR3);
	dynamicsWorld->addConstraint(shoulderL3);
	dynamicsWorld->addConstraint(shoulderR4);
	dynamicsWorld->addConstraint(shoulderL4);
	dynamicsWorld->addConstraint(shoulderR5);
	dynamicsWorld->addConstraint(shoulderL5);
	dynamicsWorld->addConstraint(shoulderR6);
	dynamicsWorld->addConstraint(shoulderL6);
	dynamicsWorld->addConstraint(shoulderR7);
	dynamicsWorld->addConstraint(shoulderL7);
	dynamicsWorld->addConstraint(shoulderR8);
	dynamicsWorld->addConstraint(shoulderL8);
	dynamicsWorld->addConstraint(shoulderR9);
	dynamicsWorld->addConstraint(shoulderL9);

	shared_ptr<PhysicsController> neck = physicsFactory->CreateCylinder(connectRad, connectLength, glm::vec3(0, scale, -(head_rad)), neck_rot);
	shared_ptr<PhysicsController> connector1 = physicsFactory->CreateCylinder(connectRad, connectLength, glm::vec3(0, scale, -(head_rad)-5 - diameter), neck_rot);
	shared_ptr<PhysicsController> connector2 = physicsFactory->CreateCylinder(connectRad, connectLength, glm::vec3(0, scale, -(head_rad)-10 - (diameter * 2)), neck_rot);
	shared_ptr<PhysicsController> connector3 = physicsFactory->CreateCylinder(connectRad, connectLength, glm::vec3(0, scale, -(head_rad)-15 - (diameter * 3)), neck_rot);
	shared_ptr<PhysicsController> connector4 = physicsFactory->CreateCylinder(connectRad, connectLength, glm::vec3(0, scale, -(head_rad)-20 - (diameter * 4)), neck_rot);
	shared_ptr<PhysicsController> connector5 = physicsFactory->CreateCylinder(connectRad, connectLength, glm::vec3(0, scale, -(head_rad)-25 - (diameter * 5)), neck_rot);
	shared_ptr<PhysicsController> connector6 = physicsFactory->CreateCylinder(connectRad, connectLength, glm::vec3(0, scale, -(head_rad)-30 - (diameter * 6)), neck_rot);
	shared_ptr<PhysicsController> connector7 = physicsFactory->CreateCylinder(connectRad, connectLength, glm::vec3(0, scale, -(head_rad)-35 - (diameter * 7)), neck_rot);
	shared_ptr<PhysicsController> connector8 = physicsFactory->CreateCylinder(connectRad, connectLength, glm::vec3(0, scale, -(head_rad)-40 - (diameter * 8)), neck_rot);

	btHingeConstraint * neck_bend = new btHingeConstraint(*head->rigidBody, *neck->rigidBody, GLToBtVector(glm::vec3(((head_rad + connectRad)* (1 / glm::sqrt(2.0))), ((scale)* (1 / glm::sqrt(2.0))), 0)), GLToBtVector(glm::vec3(connectRad, 0, 0)), btVector3(0, 0, 0), btVector3(0, 1, 0));
	btHingeConstraint * body_bend1 = new btHingeConstraint(*neck->rigidBody, *bodySegment1->rigidBody, GLToBtVector(glm::vec3(((scale + connectRad)* (1 / glm::sqrt(2.0))), ((scale)* (1 / glm::sqrt(2.0))), 0)), GLToBtVector(glm::vec3(-connectRad, 0, 0)), btVector3(0, 0, 0), btVector3(0, 1, 0));
	btHingeConstraint * body_bend2 = new btHingeConstraint(*bodySegment1->rigidBody, *connector1->rigidBody, GLToBtVector(glm::vec3(((scale + connectRad)* (1 / glm::sqrt(2.0))), ((scale)* (1 / glm::sqrt(2.0))), 0)), GLToBtVector(glm::vec3(connectRad, 0, 0)), btVector3(0, 0, 0), btVector3(0, 1, 0));
	btHingeConstraint * body_bend3 = new btHingeConstraint(*connector1->rigidBody, *bodySegment2->rigidBody, GLToBtVector(glm::vec3(((scale + connectRad)* (1 / glm::sqrt(2.0))), ((scale)* (1 / glm::sqrt(2.0))), 0)), GLToBtVector(glm::vec3(-connectRad, 0, 0)), btVector3(0, 0, 0), btVector3(0, 1, 0));
	btHingeConstraint * body_bend4 = new btHingeConstraint(*bodySegment2->rigidBody, *connector2->rigidBody, GLToBtVector(glm::vec3(((scale + connectRad)* (1 / glm::sqrt(2.0))), ((scale)* (1 / glm::sqrt(2.0))), 0)), GLToBtVector(glm::vec3(connectRad, 0, 0)), btVector3(0, 0, 0), btVector3(0, 1, 0));
	btHingeConstraint * body_bend5 = new btHingeConstraint(*connector2->rigidBody, *bodySegment3->rigidBody, GLToBtVector(glm::vec3(((scale + connectRad)* (1 / glm::sqrt(2.0))), ((scale)* (1 / glm::sqrt(2.0))), 0)), GLToBtVector(glm::vec3(-connectRad, 0, 0)), btVector3(0, 0, 0), btVector3(0, 1, 0));
	btHingeConstraint * body_bend6 = new btHingeConstraint(*bodySegment3->rigidBody, *connector3->rigidBody, GLToBtVector(glm::vec3(((scale + connectRad)* (1 / glm::sqrt(2.0))), ((scale)* (1 / glm::sqrt(2.0))), 0)), GLToBtVector(glm::vec3(connectRad, 0, 0)), btVector3(0, 0, 0), btVector3(0, 1, 0));
	btHingeConstraint * body_bend7 = new btHingeConstraint(*connector3->rigidBody, *bodySegment4->rigidBody, GLToBtVector(glm::vec3(((scale + connectRad)* (1 / glm::sqrt(2.0))), ((scale)* (1 / glm::sqrt(2.0))), 0)), GLToBtVector(glm::vec3(-connectRad, 0, 0)), btVector3(0, 0, 0), btVector3(0, 1, 0));
	btHingeConstraint * body_bend8 = new btHingeConstraint(*bodySegment4->rigidBody, *connector4->rigidBody, GLToBtVector(glm::vec3(((scale + connectRad)* (1 / glm::sqrt(2.0))), ((scale)* (1 / glm::sqrt(2.0))), 0)), GLToBtVector(glm::vec3(connectRad, 0, 0)), btVector3(0, 0, 0), btVector3(0, 1, 0));
	btHingeConstraint * body_bend9 = new btHingeConstraint(*connector4->rigidBody, *bodySegment5->rigidBody, GLToBtVector(glm::vec3(((scale + connectRad)* (1 / glm::sqrt(2.0))), ((scale)* (1 / glm::sqrt(2.0))), 0)), GLToBtVector(glm::vec3(-connectRad, 0, 0)), btVector3(0, 0, 0), btVector3(0, 1, 0));
	btHingeConstraint * body_bend10 = new btHingeConstraint(*bodySegment5->rigidBody, *connector5->rigidBody, GLToBtVector(glm::vec3(((scale + connectRad)* (1 / glm::sqrt(2.0))), ((scale)* (1 / glm::sqrt(2.0))), 0)), GLToBtVector(glm::vec3(connectRad, 0, 0)), btVector3(0, 0, 0), btVector3(0, 1, 0));
	btHingeConstraint * body_bend11 = new btHingeConstraint(*connector5->rigidBody, *bodySegment6->rigidBody, GLToBtVector(glm::vec3(((scale + connectRad)* (1 / glm::sqrt(2.0))), ((scale)* (1 / glm::sqrt(2.0))), 0)), GLToBtVector(glm::vec3(-connectRad, 0, 0)), btVector3(0, 0, 0), btVector3(0, 1, 0));
	btHingeConstraint * body_bend12 = new btHingeConstraint(*bodySegment6->rigidBody, *connector6->rigidBody, GLToBtVector(glm::vec3(((scale + connectRad)* (1 / glm::sqrt(2.0))), ((scale)* (1 / glm::sqrt(2.0))), 0)), GLToBtVector(glm::vec3(connectRad, 0, 0)), btVector3(0, 0, 0), btVector3(0, 1, 0));
	btHingeConstraint * body_bend13 = new btHingeConstraint(*connector6->rigidBody, *bodySegment7->rigidBody, GLToBtVector(glm::vec3(((scale + connectRad)* (1 / glm::sqrt(2.0))), ((scale)* (1 / glm::sqrt(2.0))), 0)), GLToBtVector(glm::vec3(-connectRad, 0, 0)), btVector3(0, 0, 0), btVector3(0, 1, 0));
	btHingeConstraint * body_bend14 = new btHingeConstraint(*bodySegment7->rigidBody, *connector7->rigidBody, GLToBtVector(glm::vec3(((scale + connectRad)* (1 / glm::sqrt(2.0))), ((scale)* (1 / glm::sqrt(2.0))), 0)), GLToBtVector(glm::vec3(connectRad, 0, 0)), btVector3(0, 0, 0), btVector3(0, 1, 0));
	btHingeConstraint * body_bend15 = new btHingeConstraint(*connector7->rigidBody, *bodySegment8->rigidBody, GLToBtVector(glm::vec3(((scale + connectRad)* (1 / glm::sqrt(2.0))), ((scale)* (1 / glm::sqrt(2.0))), 0)), GLToBtVector(glm::vec3(-connectRad, 0, 0)), btVector3(0, 0, 0), btVector3(0, 1, 0));
	btHingeConstraint * body_bend16 = new btHingeConstraint(*bodySegment8->rigidBody, *connector8->rigidBody, GLToBtVector(glm::vec3(((scale + connectRad)* (1 / glm::sqrt(2.0))), ((scale)* (1 / glm::sqrt(2.0))), 0)), GLToBtVector(glm::vec3(connectRad, 0, 0)), btVector3(0, 0, 0), btVector3(0, 1, 0));
	btHingeConstraint * body_bend17 = new btHingeConstraint(*connector8->rigidBody, *bodySegment9->rigidBody, GLToBtVector(glm::vec3(((scale + connectRad)* (1 / glm::sqrt(2.0))), ((scale)* (1 / glm::sqrt(2.0))), 0)), GLToBtVector(glm::vec3(-connectRad, 0, 0)), btVector3(0, 0, 0), btVector3(0, 1, 0));
	
	Game::dynamicsWorld->addConstraint(neck_bend);
	Game::dynamicsWorld->addConstraint(body_bend1);
	Game::dynamicsWorld->addConstraint(body_bend2);
	Game::dynamicsWorld->addConstraint(body_bend3);
	Game::dynamicsWorld->addConstraint(body_bend4);
	Game::dynamicsWorld->addConstraint(body_bend5);
	Game::dynamicsWorld->addConstraint(body_bend6);
	Game::dynamicsWorld->addConstraint(body_bend7);
	Game::dynamicsWorld->addConstraint(body_bend8);
	Game::dynamicsWorld->addConstraint(body_bend9);
	Game::dynamicsWorld->addConstraint(body_bend10);
	Game::dynamicsWorld->addConstraint(body_bend11);
	Game::dynamicsWorld->addConstraint(body_bend12);
	Game::dynamicsWorld->addConstraint(body_bend13);
	Game::dynamicsWorld->addConstraint(body_bend14);
	Game::dynamicsWorld->addConstraint(body_bend15);
	Game::dynamicsWorld->addConstraint(body_bend16);
	Game::dynamicsWorld->addConstraint(body_bend17);
	
	neck_bend->enableAngularMotor(true, 5, 5);
	body_bend1->enableAngularMotor(true, 5, 5);
	body_bend2->enableAngularMotor(true, 5, 5);
	body_bend3->enableAngularMotor(true, 5, 5);
	body_bend4->enableAngularMotor(true, 5, 5);
	body_bend5->enableAngularMotor(true, 5, 5);
	body_bend6->enableAngularMotor(true, 5, 5);
	body_bend7->enableAngularMotor(true, 5, 5);
	body_bend8->enableAngularMotor(true, 5, 5);
	body_bend9->enableAngularMotor(true, 5, 5);
	body_bend10->enableAngularMotor(true, 5, 5);
	body_bend11->enableAngularMotor(true, 5, 5);
	body_bend12->enableAngularMotor(true, 5, 5);
	body_bend13->enableAngularMotor(true, 5, 5);
	body_bend14->enableAngularMotor(true, 5, 5);
	body_bend15->enableAngularMotor(true, 5, 5);
	body_bend16->enableAngularMotor(true, 5, 5);
	body_bend17->enableAngularMotor(true, 5, 5);

	return head;
	
}

