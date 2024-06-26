#include "Simple.h"
REGISTER_COMPONENT(SimpleDetect)

void SimpleDetect::Init() { 
	
	InitPtrs();
	SetPoints(Unigine::Math::AXIS_Y, Distance, node);

	// Offset cause CenterPoint is on Floor
	P0 += Unigine::Math::Vec3(0, 0, 0.5);
	P1 += Unigine::Math::Vec3(0, 0, 0.5);

	InitLabel();
}

void SimpleDetect::Update() {
		

	Unigine::ObjectPtr Obj = Unigine::World::getIntersection(P0, P1, MaskVal,/* Ptr*/ NPtr);

	if (Obj) { 
		Label->setText(Obj->getName()); 
		Label->setFontColor(Unigine::Math::vec4_green);

		//// For Point Only
		//Unigine::Visualizer::renderPoint3D(Ptr->getPoint(), 0.05f, Unigine::Math::vec4_green);

		// For Normal
		Unigine::Visualizer::renderVector(NPtr->getPoint(), NPtr->getPoint() + Unigine::Math::Vec3(NPtr->getNormal()), Unigine::Math::vec4_green);
	}
	else { 
		Label->setText("Caught Nothing");
		Label->setFontColor(Unigine::Math::vec4_red);
	}

	Unigine::Visualizer::renderLine3D(
		P0,
		P1,
		Unigine::Math::vec4_blue
	);

}

void SimpleDetect::Shutdown() {

	if (Ptr) Ptr.deleteLater();
	if (NPtr) NPtr.deleteLater();

	Unigine::GuiPtr GUI = Unigine::Gui::getCurrent();
	if (GUI->isChild(Label))  GUI->removeChild(Label); 
	if (Label) Label.deleteLater();
}
