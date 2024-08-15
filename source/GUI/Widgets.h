#pragma once
#include <UnigineComponentSystem.h>
#include <UnigineGame.h>
#include <UnigineWidgets.h>

struct Widgets : public Unigine::ComponentBase {

public:
	COMPONENT_DEFINE(Widgets, ComponentBase);
	COMPONENT_INIT(Init);
	COMPONENT_UPDATE(Update);
	COMPONENT_SHUTDOWN(Shutdown);

protected:
	void Init(), Update(), Shutdown();
	PROP_ARRAY(File, ImageFile);
	PROP_PARAM(File, VideoFile);

private:
	void Enter(const Unigine::WidgetPtr& Widget) {

		Unigine::WidgetButtonPtr Button = Unigine::static_ptr_cast<Unigine::WidgetButton>(Widget);
		Button->setButtonColor(Unigine::Math::vec4_white);
	}

	void Leave(const Unigine::WidgetPtr& Widget) {
		
		Unigine::WidgetButtonPtr Button = Unigine::static_ptr_cast<Unigine::WidgetButton>(Widget);
		Button->setButtonColor(Unigine::Math::vec4_black);
	}

	void RotateImage();

	Unigine::WidgetButtonPtr Button;
	Unigine::WidgetCanvasPtr Canvas;
	Unigine::WidgetSpritePtr Sprite;
	float Angle{ 0 }, hSize{ 128 };
};

void Clicked(const Unigine::WidgetPtr& Widget) {
	Unigine::Log::message("Widget Clicked\n");
}