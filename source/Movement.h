#pragma once
#include <Unigine.h>

struct Movement : public Unigine::ComponentBase {

public:
	COMPONENT_DEFINE(Movement, ComponentBase)
		COMPONENT_INIT(Init)
		COMPONENT_UPDATE(Update)
		COMPONENT_UPDATE_PHYSICS(UpdatePhysics)

		PROP_PARAM(Node, MoveObj)
		PROP_PARAM(Node, MoveObj2)

protected:
	void Init(), Update(), UpdatePhysics();

private:
	void ChessMovement(), ChessRot(),  ChessCombined(), ChessFixedMovement(), ChessFixedCombined();
	void ConstMovement(), ConstRot(), ConstCombined();

	void PhysicsMovement(), PhysicsFixedMovement(), PhysicsRot(), PhysicsCombinedMovement();

	Unigine::BodyRigidPtr _Physics;
	float Speed = 10;
};

double GetSpeed(Unigine::Math::vec3 Vel) {

	double speed = Unigine::Math::length2(Vel);
	return Unigine::Math::sqrtFast(speed);
}
