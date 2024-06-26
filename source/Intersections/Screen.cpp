#include "Screen.h"
REGISTER_COMPONENT(ScreenDetect);

void ScreenDetect::Init() {

	InitPtrs();
	InitLabel();
	Label->setFontColor(Unigine::Math::vec4_green);
	
	// Mouse doesnt go into the screen
	Unigine::Input::setMouseHandle(Unigine::Input::MOUSE_HANDLE_SOFT);

	// If you dont have reference to the main Camera
	Camera = Unigine::Game::getPlayer();

	//// If you have reference to the main Camera
	//Camera = Unigine::static_ptr_cast<Unigine::Player>(CameraNode.get());

	//// If you attach this Component to the main Camera
	//Camera = Unigine::static_ptr_cast<Unigine::Player>(node);
}

void ScreenDetect::Update() {

	Unigine::Math::ivec2 MousePos = Unigine::Input::getMousePosition();
	P0 = Camera->getWorldPosition();
	P1 =  P0 + Unigine::Math::Vec3(Camera->getDirectionFromMainWindow(MousePos.x, MousePos.y) * 100 /*Distance*/);

	Unigine::ObjectPtr Ground = Unigine::World::getIntersection(P0, P1, GroundMask, Ptr);
	if (Ground) {
		
		Label->setText("Caught Ground");
		Unigine::Visualizer::renderPoint3D(Ptr->getPoint(), 0.05f, Unigine::Math::vec4_red);
	}

	Unigine::ObjectPtr Obj = Unigine::World::getIntersection(P0, P1, MaskVal, NPtr);
	if (Obj) {
		
		Label->setText(Obj->getName());
		Unigine::Visualizer::renderPoint3D(NPtr->getPoint(), 0.05f, Unigine::Math::vec4_green);
		Unigine::Visualizer::renderVector(NPtr->getPoint(), NPtr->getPoint() + Unigine::Math::Vec3(NPtr->getNormal()), Unigine::Math::vec4_green);
	}

}
