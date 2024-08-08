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

	void MoveUp()	{
		Unigine::Math::Vec3 Pos = Unigine::Math::Vec3(node->getWorldDirection(Unigine::Math::AXIS_Y));
		node->setWorldPosition(node->getWorldPosition() + Pos);
	}
	void MoveDown() {
		Unigine::Math::Vec3 Pos = Unigine::Math::Vec3(node->getWorldDirection(Unigine::Math::AXIS_NY));
		node->setWorldPosition(node->getWorldPosition() + Pos);
	}
	void MoveLeft() {
		Unigine::Math::Vec3 Pos = Unigine::Math::Vec3(node->getWorldDirection(Unigine::Math::AXIS_NX));
		node->setWorldPosition(node->getWorldPosition() + Pos);
	}
	void MoveRight(){
		Unigine::Math::Vec3 Pos = Unigine::Math::Vec3(node->getWorldDirection(Unigine::Math::AXIS_X));
		node->setWorldPosition(node->getWorldPosition() + Pos);
	}
	void RotLeft() { node->worldRotate(Unigine::Math::quat(0, 0, 15)); }
	void RotRight() { node->worldRotate(Unigine::Math::quat(0, 0, -15)); }
};

