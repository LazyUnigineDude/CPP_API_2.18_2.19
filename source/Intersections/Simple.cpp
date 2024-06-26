#include "Simple.h"
REGISTER_COMPONENT(SimpleDetect)

void SimpleDetect::Init() { 
	
	Ptr = Unigine::WorldIntersection::create();
}

void SimpleDetect::Update() {

	Unigine::ObjectPtr Obj = Unigine::World::getIntersection(
		node->getWorldPosition(),
		node->getWorldPosition() + Unigine::Math::Vec3(node->getWorldDirection(Unigine::Math::AXIS_Y)),
		MaskVal,
		Ptr
	);

}

void SimpleDetect::Shutdown() {

	if (Ptr) Ptr.deleteLater();
}