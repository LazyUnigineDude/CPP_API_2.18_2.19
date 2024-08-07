#include "Widgets.h"
REGISTER_COMPONENT(Widgets);

void Widgets::Init() {

	Button = Unigine::WidgetButton::create("Button 1");
	Button->setWidth(50);
	Button->setPosition(50, 50);

	Unigine::GuiPtr GUI = Unigine::Gui::getCurrent();
	GUI->addChild(Button, GUI->ALIGN_EXPAND | GUI->ALIGN_OVERLAP);
}

void Widgets::Shutdown() {

	Unigine::GuiPtr GUI = Unigine::Gui::getCurrent();
	if (GUI->isChild(Button)) GUI->removeChild(Button);

	if (Button) Button.deleteLater();
}
