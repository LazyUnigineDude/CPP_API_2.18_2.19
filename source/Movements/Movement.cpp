#include "Movement.h"
REGISTER_COMPONENT(Movement)

void Movement::Init() {

	_Physics = node->getObjectBodyRigid();
}

void Movement::Update() {

	//ChessMovement();
	//ChessRot();
	//ChessCombined();
	//ChessFixedMovement();
	//ChessFixedCombined();

	//ConstMovement();
	//ConstRot();
	//ConstCombined();

	//// Test
	//Unigine::Math::Vec3 Pos = Unigine::Math::Vec3(MoveObj2->getWorldDirection(Unigine::Math::AXIS_Y));
	//MoveObj2->setWorldPosition(MoveObj2->getWorldPosition() + (Pos * Unigine::Game::getIFps()));
}

void Movement::UpdatePhysics() {

	//PhysicsMovement();
	//PhysicsFixedMovement();
	//PhysicsRot();
	//PhysicsCombinedMovement();

	//// Test
	//_Physics->addLinearImpulse(node->getWorldDirection(Unigine::Math::AXIS_Y) * Speed * Unigine::Physics::getIFps());
}

void Movement::ChessMovement() {
	
	if (Unigine::Input::isKeyDown(Unigine::Input::KEY_W)) {
		node->setWorldPosition(node->getWorldPosition() + Unigine::Math::Vec3_forward);
		Unigine::Log::message("Pressed W, Forward\n");
	}

	if (Unigine::Input::isKeyDown(Unigine::Input::KEY_S)) {
		node->setWorldPosition(node->getWorldPosition() + Unigine::Math::Vec3_back);
		Unigine::Log::message("Pressed S, Backward\n");
	}


	if (Unigine::Input::isKeyDown(Unigine::Input::KEY_A)) {
		node->setWorldPosition(node->getWorldPosition() + Unigine::Math::Vec3_left);
		Unigine::Log::message("Pressed A, Left\n");
	}


	if (Unigine::Input::isKeyDown(Unigine::Input::KEY_D)) {
		node->setWorldPosition(node->getWorldPosition() + Unigine::Math::Vec3_right);
		Unigine::Log::message("Pressed D, Right\n");
	}
}

void Movement::ChessRot() {
	
	if (Unigine::Input::isKeyDown(Unigine::Input::KEY_Q)) {
		node->worldRotate(Unigine::Math::quat(0, 0, 15));
		Unigine::Log::message("Pressed Q, CounterClockwise Rotation by 15\n");
	}


	if (Unigine::Input::isKeyDown(Unigine::Input::KEY_E)) {
		node->worldRotate(Unigine::Math::quat(0, 0, -15));
		Unigine::Log::message("Pressed E, ClockWise Rotation by 15\n");
	}
}

void Movement::ChessCombined() {

	ChessMovement();
	ChessRot();
}

void Movement::ChessFixedMovement() {

	Unigine::Math::Vec3 Pos;

	if (Unigine::Input::isKeyDown(Unigine::Input::KEY_W)) {
		Pos = Unigine::Math::Vec3(node->getWorldDirection(Unigine::Math::AXIS_Y));
		node->setWorldPosition(node->getWorldPosition() + Pos);
		Unigine::Log::message("Pressed W, Forward\n");
	}

	if (Unigine::Input::isKeyDown(Unigine::Input::KEY_S)) {
		Pos = Unigine::Math::Vec3(node->getWorldDirection(Unigine::Math::AXIS_NY));
		node->setWorldPosition(node->getWorldPosition() + Pos);
		Unigine::Log::message("Pressed S, Backward\n");
	}


	if (Unigine::Input::isKeyDown(Unigine::Input::KEY_A)) {
		Pos = Unigine::Math::Vec3(node->getWorldDirection(Unigine::Math::AXIS_NX));
		node->setWorldPosition(node->getWorldPosition() + Pos);
		Unigine::Log::message("Pressed A, Left\n");
	}


	if (Unigine::Input::isKeyDown(Unigine::Input::KEY_D)) {
		Pos = Unigine::Math::Vec3(node->getWorldDirection(Unigine::Math::AXIS_X));
		node->setWorldPosition(node->getWorldPosition() + Pos);
		Unigine::Log::message("Pressed D, Right\n");
	}
}

void Movement::ChessFixedCombined() {

	ChessFixedMovement();
	ChessRot();
}

///////////////////////////////////////////////////////////////////

void Movement::ConstMovement() {

	Unigine::Math::Vec3 Pos;
	if (Unigine::Input::isKeyPressed(Unigine::Input::KEY_W)) {
		Pos = Unigine::Math::Vec3(node->getWorldDirection(Unigine::Math::AXIS_Y));
		node->setWorldPosition(node->getWorldPosition() + (Pos * Unigine::Game::getIFps()));
		Unigine::Log::message("Pressed W, Forward\n");
	}

	if (Unigine::Input::isKeyPressed(Unigine::Input::KEY_S)) {
		Pos = Unigine::Math::Vec3(node->getWorldDirection(Unigine::Math::AXIS_NY));
		node->setWorldPosition(node->getWorldPosition() + (Pos * Unigine::Game::getIFps()));
		Unigine::Log::message("Pressed S, Backward\n");
	}


	if (Unigine::Input::isKeyPressed(Unigine::Input::KEY_A)) {
		Pos = Unigine::Math::Vec3(node->getWorldDirection(Unigine::Math::AXIS_NX));
		node->setWorldPosition(node->getWorldPosition() + (Pos * Unigine::Game::getIFps()));
		Unigine::Log::message("Pressed A, Left\n");
	}


	if (Unigine::Input::isKeyPressed(Unigine::Input::KEY_D)) {
		Pos = Unigine::Math::Vec3(node->getWorldDirection(Unigine::Math::AXIS_X));
		node->setWorldPosition(node->getWorldPosition() + (Pos * Unigine::Game::getIFps()));
		Unigine::Log::message("Pressed D, Right\n");
	}
}

void Movement::ConstRot() {

	if (Unigine::Input::isKeyPressed(Unigine::Input::KEY_Q)) {
		node->worldRotate(Unigine::Math::quat(0, 0, 1));
		Unigine::Log::message("Pressed Q, CounterClockwise Rotation\n");
	}


	if (Unigine::Input::isKeyPressed(Unigine::Input::KEY_E)) {
		node->worldRotate(Unigine::Math::quat(0, 0, -1));
		Unigine::Log::message("Pressed E, ClockWise Rotation\n");
	}
}

void Movement::ConstCombined() {

	ConstMovement();
	ConstRot();
}

////////////////////////////////////////////////////////////////


void Movement::PhysicsMovement() {

	if (Unigine::Input::isKeyPressed(Unigine::Input::KEY_W)) {
		_Physics->addLinearImpulse(Unigine::Math::vec3_forward );
		Unigine::Log::message("Pressed W, Forward\n");
	}

	if (Unigine::Input::isKeyPressed(Unigine::Input::KEY_S)) {
		_Physics->addLinearImpulse(Unigine::Math::vec3_back );
		Unigine::Log::message("Pressed S, Backward\n");
	}

	if (Unigine::Input::isKeyPressed(Unigine::Input::KEY_A)) {
		_Physics->addLinearImpulse(Unigine::Math::vec3_left );
		Unigine::Log::message("Pressed A, Left\n");
	}

	if (Unigine::Input::isKeyPressed(Unigine::Input::KEY_D)) {
		_Physics->addLinearImpulse(Unigine::Math::vec3_right );
		Unigine::Log::message("Pressed D, Right\n");
	}
}

void Movement::PhysicsFixedMovement() {

	float _Speed = Speed * Unigine::Physics::getIFps();

	if (Unigine::Input::isKeyPressed(Unigine::Input::KEY_W)) {
		_Physics->addLinearImpulse(node->getWorldDirection(Unigine::Math::AXIS_Y) * _Speed);
		Unigine::Log::message("Pressed W, Forward\n");
	}

	if (Unigine::Input::isKeyPressed(Unigine::Input::KEY_S)) {
		_Physics->addLinearImpulse(node->getWorldDirection(Unigine::Math::AXIS_NY) * _Speed);
		Unigine::Log::message("Pressed S, Backward\n");
	}

	if (Unigine::Input::isKeyPressed(Unigine::Input::KEY_A)) {
		_Physics->addLinearImpulse(node->getWorldDirection(Unigine::Math::AXIS_NX) * _Speed);
		Unigine::Log::message("Pressed A, Left\n");
	}

	if (Unigine::Input::isKeyPressed(Unigine::Input::KEY_D)) {
		_Physics->addLinearImpulse(node->getWorldDirection(Unigine::Math::AXIS_X) * _Speed);
		Unigine::Log::message("Pressed D, Right\n");
	}
	////Speed
	//Unigine::Log::message("Speed: %.2f \n", GetSpeed(_Physics->getLinearVelocity()));
}

void Movement::PhysicsRot() {

	if (Unigine::Input::isKeyPressed(Unigine::Input::KEY_Q)) {
		_Physics->addAngularImpulse(-node->getWorldDirection() * Unigine::Physics::getIFps());
		Unigine::Log::message("Pressed Q, CounterClockwise Rotation\n");
	}


	if (Unigine::Input::isKeyPressed(Unigine::Input::KEY_E)) {
		_Physics->addAngularImpulse(node->getWorldDirection() * Unigine::Physics::getIFps());
		Unigine::Log::message("Pressed E, ClockWise Rotation\n");
	}
}

void Movement::PhysicsCombinedMovement() {
	
	PhysicsFixedMovement();
	PhysicsRot();
}