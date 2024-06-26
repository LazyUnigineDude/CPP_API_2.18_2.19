#pragma once
#include <UnigineComponentSystem.h>
#include <UnigineGame.h>

struct ConstMovement : public Unigine::ComponentBase {

public:
	COMPONENT_DEFINE(ConstMovement, ComponentBase);

	void Movement();
	void Rot();
	void Combined();

private:
	float Speed = 10;
};