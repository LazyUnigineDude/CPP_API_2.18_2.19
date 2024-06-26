#include "GettingComponentsLogic.h"
REGISTER_COMPONENT(GettingComponentsLogic)

void GettingComponentsLogic::Init() {
	
	//1. Component Click and Drag

	//2. World ID
	Unigine::NodePtr _Node = Unigine::World::getNodeByID(1492681673);
	Unigine::Log::message("Caught: %s, ID: %d\n", _Node->getName(), _Node->getID());

	//3. World Name
	_Node = Unigine::World::getNodeByName("MatBall");
	Unigine::Log::message("Caught: %s, ID: %d\n", _Node->getName(), _Node->getID());

	//4. Get Custom Component from NodeItem
	_Movement = getComponent<ChessMovement>(NodeItem);

	//5. Get Unigine Component from the Node
	Unigine::ObjectPtr Obj = Unigine::checked_ptr_cast<Unigine::Object>(NodeItem.get());

	if (Obj->isClutterInteractionEnabled()) Unigine::Log::message("Clutter Intersection is Enabled\n");
	else Unigine::Log::message("Clutter Intersection is Disabled\n");
}

void GettingComponentsLogic::Update() {
	if (_Movement) _Movement->FixedCombined();
}
