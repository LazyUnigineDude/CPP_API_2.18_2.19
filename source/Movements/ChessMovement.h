#pragma once
#include <UnigineComponentSystem.h>

struct ChessMovement : public Unigine::ComponentBase {

public:
	COMPONENT_DEFINE(ChessMovement, ComponentBase)

		//PROP_PARAM(Node, node)
		//PROP_PARAM(Node, MoveObj2)

	void Movement();
	void Rot();
	void Combined();
	void FixedMove();
	void FixedCombine();

private:
	Unigine::BodyRigidPtr _Physics;
	float Speed = 10;
};

