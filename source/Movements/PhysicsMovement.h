#pragma once
#include <UniginePhysics.h>
#include <UnigineComponentSystem.h>

struct PhysicsMovement : public Unigine::ComponentBase {

public:
	COMPONENT_DEFINE(PhysicsMovement, ComponentBase);
	
	void Init() { _Physics = node->getObjectBodyRigid(); }
	void Movement();
	void FixedMovement();
	void Rot();
	void Combined();


private:
	Unigine::BodyRigidPtr _Physics;
	float Speed = 10;
};
