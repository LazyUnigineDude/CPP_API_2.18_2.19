#pragma once
#include <UnigineWidgets.h>
#include <UnigineComponentSystem.h>
#include "../Movements/ChessMovement.h"

struct ChessGUI : public Unigine::ComponentBase {

public:
	COMPONENT_DEFINE(ChessGUI, ComponentBase);
	COMPONENT_INIT(Init);
	COMPONENT_SHUTDOWN(Shutdown);

protected:
	void Init(), Shutdown();
	PROP_PARAM(Node, ChessNode);

private:
	void 
		ClickUp(const Unigine::WidgetPtr& Button),
		ClickDown(const Unigine::WidgetPtr& Button), 
		ClickLeft(const Unigine::WidgetPtr& Button), 
		ClickRight(const Unigine::WidgetPtr& Button), 
		ClickRLeft(const Unigine::WidgetPtr& Button), 
		ClickRRight(const Unigine::WidgetPtr& Button);

	ChessMovement* Move;
	Unigine::WidgetButtonPtr Up, Down, Left, Right, RLeft, RRight;
};

void Enter(const Unigine::WidgetPtr& Widget) {

	Unigine::WidgetButtonPtr Button = Unigine::static_ptr_cast<Unigine::WidgetButton>(Widget);
	Button->setButtonColor(Unigine::Math::vec4_red);
}

void Leave(const Unigine::WidgetPtr& Widget) {

	Unigine::WidgetButtonPtr Button = Unigine::static_ptr_cast<Unigine::WidgetButton>(Widget);
	Button->setButtonColor(Unigine::Math::vec4_white);
}