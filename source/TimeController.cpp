#include "TimeController.h"
REGISTER_COMPONENT(TimeController)


void TimeController::Init() {

	Unigine::GuiPtr GUI = Unigine::Gui::getCurrent();

	AsyncLabel = Unigine::WidgetLabel::create();
	AsyncLabel->setFontSize(16);
	AsyncLabel->setPosition(50, 100);

	UpdateLabel = Unigine::WidgetLabel::create();
	UpdateLabel->setFontSize(16);
	UpdateLabel->setPosition(50, 125);

	PhysicsLabel = Unigine::WidgetLabel::create();
	PhysicsLabel->setFontSize(16);
	PhysicsLabel->setPosition(50, 150);

	GUI->addChild(AsyncLabel, GUI->ALIGN_EXPAND | GUI->ALIGN_OVERLAP);
	GUI->addChild(UpdateLabel, GUI->ALIGN_EXPAND | GUI->ALIGN_OVERLAP);
	GUI->addChild(PhysicsLabel, GUI->ALIGN_EXPAND | GUI->ALIGN_OVERLAP);


	TimeSlider = Unigine::WidgetSlider::create(1, 5, 1);
	TimeSlider->setWidth(150);
	TimeSlider->setPosition(100, 200);
	TimeSlider->getEventChanged().connect([&]() {Time = 0; });
	GUI->addChild(TimeSlider, GUI->ALIGN_EXPAND | GUI->ALIGN_OVERLAP);
}

void TimeController::UpdateAsync() {

	std::string _Speed = "Async Time: " + FloatToString(Unigine::Game::getTime(), 2) + " Seconds";
	AsyncLabel->setText(_Speed.c_str());
}

void TimeController::Update() {

	std::string _Speed = "Update: " + FloatToString(Unigine::Game::getIFps()) + " Seconds";
	UpdateLabel->setText(_Speed.c_str());
	MoveObject();
}

void TimeController::UpdatePhysics() {

	std::string _Speed = "Physics: " + FloatToString(Unigine::Physics::getIFps()) + " Seconds";
	PhysicsLabel->setText(_Speed.c_str());
}

void TimeController::Shutdown() {
	
	Unigine::GuiPtr GUI = Unigine::Gui::getCurrent();

	if (GUI->isChild(AsyncLabel)) GUI->removeChild(AsyncLabel);
	if (GUI->isChild(UpdateLabel)) GUI->removeChild(UpdateLabel);
	if (GUI->isChild(PhysicsLabel)) GUI->removeChild(PhysicsLabel);


	AsyncLabel.deleteLater();
	UpdateLabel.deleteLater();
	PhysicsLabel.deleteLater();
}

void TimeController::MoveObject() {

	Time += Unigine::Game::getIFps();
	Unigine::Math::Vec3 Pos = Unigine::Math::lerp(Unigine::Math::Vec3_zero, Unigine::Math::Vec3_left * -4, Time/TimeSlider->getValue());
	node->setWorldPosition(Pos);
	if (Time > TimeSlider->getValue()) Time = 0;
}