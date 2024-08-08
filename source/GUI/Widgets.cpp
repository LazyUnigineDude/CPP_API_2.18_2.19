#include "Widgets.h"
REGISTER_COMPONENT(Widgets);

void Widgets::Init() {

	Button = Unigine::WidgetButton::create("Click Me");
	Button->setWidth(50);
	Button->setPosition(200, 200);
	Button->setFontSize(21);
	Button->setFontColor(Unigine::Math::vec4_red);
	Button->setButtonColor(Unigine::Math::vec4_black);

	Button->getEventEnter().connect(this, &Widgets::Enter);
	Button->getEventLeave().connect(this, &Widgets::Leave);
	Button->getEventClicked().connect(&Clicked);

	Unigine::GuiPtr GUI = Unigine::Gui::getCurrent();
	GUI->addChild(Button, GUI->ALIGN_EXPAND | GUI->ALIGN_OVERLAP);
}

void Widgets::Shutdown() {

	Unigine::GuiPtr GUI = Unigine::Gui::getCurrent();
	if (GUI->isChild(Button)) GUI->removeChild(Button);

	if (Button) Button.deleteLater();
}
