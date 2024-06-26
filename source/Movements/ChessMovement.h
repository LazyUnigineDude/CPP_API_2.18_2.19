#pragma once
#include <UnigineComponentSystem.h>

struct ChessMovement : public Unigine::ComponentBase {

public:
	COMPONENT_DEFINE(ChessMovement, ComponentBase);

	void Movement();
	void Rot();
	void Combined();
	void FixedMove();
	void FixedCombined();
};

