#pragma once
#include <UnigineComponentSystem.h>
#include <UnigineGame.h>

struct ConstMovement : public Unigine::ComponentBase {

public:
	COMPONENT_DEFINE(ConstMovement, ComponentBase);
	COMPONENT_UPDATE(Update)

	void Movement();
	void Rot();
	void Combined();
	void Update() { Combined(); }

private:
	float Speed = 10;
};