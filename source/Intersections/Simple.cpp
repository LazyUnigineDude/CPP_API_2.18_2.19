#include "Simple.h"
REGISTER_COMPONENT(SimpleDetect)

void SimpleDetect::Init() { 
	
	Ptr = Unigine::WorldIntersection::create();
	Label = Unigine::WidgetLabel::create();
	Label->setFontSize(21);
	Label->setFontOutline(2);

	Unigine::GuiPtr GUI = Unigine::Gui::getCurrent();
	GUI->addChild(Label, GUI->ALIGN_CENTER | GUI->ALIGN_OVERLAP);

	P0 = node->getWorldPosition();
	P1 = node->getWorldPosition() + 
		Unigine::Math::Vec3(node->getWorldDirection(Unigine::Math::AXIS_Y) * Distance);

	P0 += Unigine::Math::Vec3(0, 0, 0.5);
	P1 += Unigine::Math::Vec3(0, 0, 0.5);
}

void SimpleDetect::Update() {
		

	Unigine::ObjectPtr Obj = Unigine::World::getIntersection(P0, P1, MaskVal, Ptr);

	if (Obj) { 
		Label->setText(Obj->getName()); 
		Label->setFontColor(Unigine::Math::vec4_green);
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

	Unigine::GuiPtr GUI = Unigine::Gui::getCurrent();
	if (GUI->isChild(Label))  GUI->removeChild(Label); 
	if (Label) Label.deleteLater();
}