#pragma once
#include <UnigineComponentSystem.h>

struct Movement : public Unigine::ComponentBase {

public:
	COMPONENT_DEFINE(Movement, ComponentBase)
		COMPONENT_INIT(Init)
		COMPONENT_UPDATE(Update)
		COMPONENT_UPDATE_PHYSICS(UpdatePhysics)

		//PROP_PARAM(Node, node)
		//PROP_PARAM(Node, MoveObj2)

		void ChessMovement();

protected:
	void Init(), Update(), UpdatePhysics();

private:
	void ChessRot(),  ChessCombined(), ChessFixedMovement(), ChessFixedCombined();
	void ConstMovement(), ConstRot(), ConstCombined();

	void PhysicsMovement(), PhysicsFixedMovement(), PhysicsRot(), PhysicsCombinedMovement();

	Unigine::BodyRigidPtr _Physics;
	float Speed = 10;
};

inline double GetSpeed(Unigine::Math::vec3 Vel) {

	double speed = Unigine::Math::length2(Vel);
	return Unigine::Math::sqrtFast(speed);
}
