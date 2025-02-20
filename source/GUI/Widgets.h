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
	PROP_PARAM(File, SoundFile);
	PROP_PARAM(File, VideoFile);
	PROP_PARAM(Material, MaterialFile);
	PROP_PARAM(Node, GUINode);
	PROP_PARAM(Node, SoundNode);
	PROP_PARAM(Node, GUIMeshNode);

private:
	void Enter(const Unigine::WidgetPtr& Widget) {

		Unigine::WidgetButtonPtr Button = Unigine::static_ptr_cast<Unigine::WidgetButton>(Widget);
		Button->setButtonColor(Unigine::Math::vec4_white);
	}

	void Leave(const Unigine::WidgetPtr& Widget) {
		
		Unigine::WidgetButtonPtr Button = Unigine::static_ptr_cast<Unigine::WidgetButton>(Widget);
		Button->setButtonColor(Unigine::Math::vec4_black);
	}

	void RotateImage(int clockWise);

	Unigine::WidgetLabelPtr Label;
	Unigine::WidgetButtonPtr Button;
	Unigine::WidgetSliderPtr Slider;
	Unigine::WidgetCanvasPtr Canvas;
	Unigine::WidgetSpritePtr Sprite;
	Unigine::WidgetSpriteShaderPtr Shader;
	Unigine::WidgetSpriteVideoPtr Video;
	Unigine::WidgetDialogColorPtr Color;

	Unigine::SoundSourcePtr Sound;
	Unigine::AmbientSourcePtr Ambience;
	float Angle{ 0 }, hSize{ 128 };

	Unigine::EventConnections EC;
};

void Clicked(const Unigine::WidgetPtr& Widget) {
	Unigine::Log::message("Widget Clicked\n");
}