#pragma once
#include "ChessMovement.h"
#include "ConstMovement.h"
#include "PhysicsMovement.h"

struct Movement : public Unigine::ComponentBase {

public:
	COMPONENT_DEFINE(Movement, ComponentBase);
	COMPONENT_INIT(Init);
	COMPONENT_UPDATE(Update);
	COMPONENT_UPDATE_PHYSICS(UpdatePhysics);

	PROP_PARAM(Node, ChessNode);
	PROP_PARAM(Node, ConstNode);
	PROP_PARAM(Node, PhysicNode);
 
protected:
	void Init(), Update(), UpdatePhysics();

private:
	ChessMovement* Chess;
	ConstMovement* Const;
	PhysicsMovement* Physics;
};

inline double GetSpeed(Unigine::Math::vec3 Vel) {

	double speed = Unigine::Math::length2(Vel);
	return Unigine::Math::sqrtFast(speed);
}
