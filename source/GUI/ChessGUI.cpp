#include "ChessGUI.h"
REGISTER_COMPONENT(ChessGUI);

void ChessGUI::Init() {

	Move = getComponent<ChessMovement>(ChessNode);

	Up = Unigine::WidgetButton::create("UP");
	Down = Unigine::WidgetButton::create("DOWN");
	Left = Unigine::WidgetButton::create("LEFT");
	Right = Unigine::WidgetButton::create("RIGHT");
	RLeft = Unigine::WidgetButton::create("ROTATE LEFT");
	RRight = Unigine::WidgetButton::create("ROTATE RIGHT");

	Up->setPosition(250, 125);
	Down->setPosition(250, 175);
	Left->setPosition(200, 150);
	Right->setPosition(300, 150);
	RLeft->setPosition(150, 100);
	RRight->setPosition(300, 100);

	Up->getEventEnter().connect(Enter);
	Up->getEventLeave().connect(Leave);
	Up->getEventClicked().connect(this, &ChessGUI::ClickUp);

	Down->getEventEnter().connect(Enter);
	Down->getEventLeave().connect(Leave);
	Down->getEventClicked().connect(this, &ChessGUI::ClickDown);

	Left->getEventEnter().connect(Enter);
	Left->getEventLeave().connect(Leave);
	Left->getEventClicked().connect(this, &ChessGUI::ClickLeft);

	Right->getEventEnter().connect(Enter);
	Right->getEventLeave().connect(Leave);
	Right->getEventClicked().connect(this, &ChessGUI::ClickRight);

	RLeft->getEventEnter().connect(Enter);
	RLeft->getEventLeave().connect(Leave);
	RLeft->getEventClicked().connect(this, &ChessGUI::ClickRLeft);

	RRight->getEventEnter().connect(Enter);
	RRight->getEventLeave().connect(Leave);
	RRight->getEventClicked().connect(this, &ChessGUI::ClickRRight);

	Unigine::GuiPtr GUI = Unigine::Gui::getCurrent();
	GUI->addChild(Up, GUI->ALIGN_OVERLAP | GUI->ALIGN_EXPAND);
	GUI->addChild(Down, GUI->ALIGN_OVERLAP | GUI->ALIGN_EXPAND);
	GUI->addChild(Left, GUI->ALIGN_OVERLAP | GUI->ALIGN_EXPAND);
	GUI->addChild(Right, GUI->ALIGN_OVERLAP | GUI->ALIGN_EXPAND);
	GUI->addChild(RLeft, GUI->ALIGN_OVERLAP | GUI->ALIGN_EXPAND);
	GUI->addChild(RRight, GUI->ALIGN_OVERLAP | GUI->ALIGN_EXPAND);
}

void ChessGUI::Shutdown() {

	Unigine::GuiPtr GUI = Unigine::Gui::getCurrent();
	if (GUI->isChild(Up)) GUI->removeChild(Up);
	if (GUI->isChild(Down)) GUI->removeChild(Down);
	if (GUI->isChild(Left)) GUI->removeChild(Left);
	if (GUI->isChild(Right)) GUI->removeChild(Right);
	if (GUI->isChild(RLeft)) GUI->removeChild(RLeft);
	if (GUI->isChild(RRight)) GUI->removeChild(RRight);

	Up.deleteLater();
	Down.deleteLater();
	Left.deleteLater();
	Right.deleteLater();
	RLeft.deleteLater();
	RRight.deleteLater();
}

void ChessGUI::ClickUp(const Unigine::WidgetPtr& Button) { if (Move) Move->MoveUp(); }
void ChessGUI::ClickDown(const Unigine::WidgetPtr& Button) { if (Move) Move->MoveDown(); }
void ChessGUI::ClickLeft(const Unigine::WidgetPtr& Button) { if (Move) Move->MoveLeft(); }
void ChessGUI::ClickRight(const Unigine::WidgetPtr& Button) { if (Move) Move->MoveRight(); }

void ChessGUI::ClickRLeft(const Unigine::WidgetPtr& Button) { if (Move) Move->RotLeft(); }
void ChessGUI::ClickRRight(const Unigine::WidgetPtr& Button) { if (Move) Move->RotRight(); }
