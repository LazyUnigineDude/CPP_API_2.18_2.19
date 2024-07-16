#include "Movement.h"
REGISTER_COMPONENT(ChessMovement)
REGISTER_COMPONENT(ConstMovement)
REGISTER_COMPONENT(PhysicsMovement)
REGISTER_COMPONENT(Movement)

void Movement::Init() {

	if (ChessNode) Chess = getComponent<ChessMovement>(ChessNode);
	if (ConstNode) Const = getComponent<ConstMovement>(ConstNode);
	if (PhysicNode) Physics = getComponent<PhysicsMovement>(PhysicNode);

	if(Physics) Physics->Init();
}

void Movement::Update() {
	
	if (Chess) Chess->FixedCombined();
	if (Const) Const->Combined();

	//// Test
	//Unigine::Math::Vec3 Pos = Unigine::Math::Vec3(MoveObj2->getWorldDirection(Unigine::Math::AXIS_Y));
	//MoveObj2->setWorldPosition(MoveObj2->getWorldPosition() + (Pos * Unigine::Game::getIFps()));
}

void Movement::UpdatePhysics() {
	
	if (Physics) Physics->Combined();

	//// Test
	//_Physics->addLinearImpulse(node->getWorldDirection(Unigine::Math::AXIS_Y) * Speed * Unigine::Physics::getIFps());
}

void ChessMovement::Movement() {
	
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

void ChessMovement::Rot() {
	
	if (Unigine::Input::isKeyDown(Unigine::Input::KEY_Q)) {
		node->worldRotate(Unigine::Math::quat(0, 0, 15));
		Unigine::Log::message("Pressed Q, CounterClockwise Rotation by 15\n");
	}


	if (Unigine::Input::isKeyDown(Unigine::Input::KEY_E)) {
		node->worldRotate(Unigine::Math::quat(0, 0, -15));
		Unigine::Log::message("Pressed E, ClockWise Rotation by 15\n");
	}
}

void ChessMovement::Combined() {

	Movement();
	Rot();
}

void ChessMovement::FixedMove() {

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

void ChessMovement::FixedCombined() {

	FixedMove();
	Rot();
}

///////////////////////////////////////////////////////////////////

void ConstMovement::Movement() {

	Unigine::Math::Vec3 Pos;
	if (Unigine::Input::isKeyPressed(Unigine::Input::KEY_W)) {
		Pos = Unigine::Math::Vec3(node->getWorldDirection(Unigine::Math::AXIS_Y));
		node->setWorldPosition(node->getWorldPosition() + (Pos * Unigine::Game::getIFps()));
		//Unigine::Log::message("Pressed W, Forward\n");
	}

	if (Unigine::Input::isKeyPressed(Unigine::Input::KEY_S)) {
		Pos = Unigine::Math::Vec3(node->getWorldDirection(Unigine::Math::AXIS_NY));
		node->setWorldPosition(node->getWorldPosition() + (Pos * Unigine::Game::getIFps()));
		//Unigine::Log::message("Pressed S, Backward\n");
	}


	if (Unigine::Input::isKeyPressed(Unigine::Input::KEY_A)) {
		Pos = Unigine::Math::Vec3(node->getWorldDirection(Unigine::Math::AXIS_NX));
		node->setWorldPosition(node->getWorldPosition() + (Pos * Unigine::Game::getIFps()));
		//Unigine::Log::message("Pressed A, Left\n");
	}


	if (Unigine::Input::isKeyPressed(Unigine::Input::KEY_D)) {
		Pos = Unigine::Math::Vec3(node->getWorldDirection(Unigine::Math::AXIS_X));
		node->setWorldPosition(node->getWorldPosition() + (Pos * Unigine::Game::getIFps()));
		//Unigine::Log::message("Pressed D, Right\n");
	}
}

void ConstMovement::Rot() {

	if (Unigine::Input::isKeyPressed(Unigine::Input::KEY_Q)) {
		node->worldRotate(Unigine::Math::quat(0, 0, 1));
		//Unigine::Log::message("Pressed Q, CounterClockwise Rotation\n");
	}


	if (Unigine::Input::isKeyPressed(Unigine::Input::KEY_E)) {
		node->worldRotate(Unigine::Math::quat(0, 0, -1));
		//Unigine::Log::message("Pressed E, ClockWise Rotation\n");
	}
}

void ConstMovement::Combined() {

	Movement();
	Rot();
}

////////////////////////////////////////////////////////////////


void PhysicsMovement::Movement() {

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

void PhysicsMovement::FixedMovement() {

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

void PhysicsMovement::Rot() {

	if (Unigine::Input::isKeyPressed(Unigine::Input::KEY_Q)) {
		_Physics->addAngularImpulse(-node->getWorldDirection() * Unigine::Physics::getIFps());
		Unigine::Log::message("Pressed Q, CounterClockwise Rotation\n");
	}


	if (Unigine::Input::isKeyPressed(Unigine::Input::KEY_E)) {
		_Physics->addAngularImpulse(node->getWorldDirection() * Unigine::Physics::getIFps());
		Unigine::Log::message("Pressed E, ClockWise Rotation\n");
	}
}

void PhysicsMovement::Combined() {
	
	FixedMovement();
	Rot();
}