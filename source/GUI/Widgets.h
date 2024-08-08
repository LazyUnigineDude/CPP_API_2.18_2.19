#pragma once
#include <UnigineComponentSystem.h>
#include <UnigineWidgets.h>

struct Widgets : public Unigine::ComponentBase {

public:
	COMPONENT_DEFINE(Widgets, ComponentBase);
	COMPONENT_INIT(Init);
	COMPONENT_SHUTDOWN(Shutdown);

protected:
	void Init(), Shutdown();

private:
	void Enter(const Unigine::WidgetPtr& Widget) {

		Unigine::WidgetButtonPtr Button = Unigine::static_ptr_cast<Unigine::WidgetButton>(Widget);
		Button->setButtonColor(Unigine::Math::vec4_white);
	}

	void Leave(const Unigine::WidgetPtr& Widget) {
		
		Unigine::WidgetButtonPtr Button = Unigine::static_ptr_cast<Unigine::WidgetButton>(Widget);
		Button->setButtonColor(Unigine::Math::vec4_black);
	}

	Unigine::EventConnection EC;
	Unigine::WidgetButtonPtr Button;
};

void Clicked(const Unigine::WidgetPtr& Widget) {
	Unigine::Log::message("Widget Clicked\n");
}