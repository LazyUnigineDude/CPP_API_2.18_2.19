#pragma once
#include <UnigineWorld.h>
#include <UnigineComponentSystem.h>
#include <UnigineVisualizer.h>

struct SimpleDetect : public Unigine::ComponentBase {

public:
	COMPONENT_DEFINE(SimpleDetect, ComponentBase);
	COMPONENT_INIT(Init);
	COMPONENT_UPDATE(Update);
	COMPONENT_SHUTDOWN(Shutdown);
	
protected:
	PROP_PARAM(Mask, MaskVal, 0x02);
	void Init(), Update(), Shutdown();

	Unigine::WorldIntersectionPtr Ptr;
	Unigine::WorldIntersectionNormalPtr NPtr;
	Unigine::WidgetLabelPtr Label;
	
	void InitPtrs() {
		Ptr = Unigine::WorldIntersection::create();
		NPtr = Unigine::WorldIntersectionNormal::create();

	}

	void InitLabel() {

		Label = Unigine::WidgetLabel::create();
		Label->setFontSize(21);
		Label->setFontOutline(2);

		Unigine::GuiPtr GUI = Unigine::Gui::getCurrent();
		GUI->addChild(Label, GUI->ALIGN_CENTER | GUI->ALIGN_OVERLAP);
	}

	void SetPoints(Unigine::Math::AXIS _Axis, int _Distance, Unigine::NodePtr Node) {

		P0 = Node->getWorldPosition();
		P1 = Unigine::Math::Vec3(Node->getWorldDirection(_Axis) * _Distance);
		P1 += P0;
	}

	Unigine::Math::Vec3 P0, P1,
		Offset{ 0, 0, 0.5 };
	int Distance{ 10 };
};