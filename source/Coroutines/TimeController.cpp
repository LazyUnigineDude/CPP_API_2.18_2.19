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


	TimeSlider = Unigine::WidgetSlider::create(1, 5, 3);
	TimeSlider->setWidth(150);
	TimeSlider->setPosition(100, 200);
	TimeSlider->getEventChanged().connect([&]() {Time = 0; });
	GUI->addChild(TimeSlider, GUI->ALIGN_EXPAND | GUI->ALIGN_OVERLAP);

	StartAnim = Unigine::WidgetButton::create("Play");
	StartAnim->setPosition(100, 250);
	StartAnim->getEventClicked().connect([=]() { canAnimate = 1; });
	GUI->addChild(StartAnim, GUI->ALIGN_EXPAND | GUI->ALIGN_OVERLAP);

	for (int i = 0; i < Objects.size(); i++) {
		Starts.emplace_back(Objects[i]->getWorldPosition());
	}
}

void TimeController::UpdateAsync() {

	std::string _Speed = "Async Time: " + FloatToString(Unigine::Game::getTime(), 2) + " Seconds";
	AsyncLabel->setText(_Speed.c_str());
}

void TimeController::Update() {

	std::string _Speed = "Update: " + FloatToString(Unigine::Game::getIFps()) + " Frames";
	UpdateLabel->setText(_Speed.c_str());
	if(canAnimate) nodeects();
}

void TimeController::UpdatePhysics() {

	std::string _Speed = "Physics: " + FloatToString(Unigine::Physics::getIFps()) + " Frames 1/60";
	PhysicsLabel->setText(_Speed.c_str());
}

void TimeController::Shutdown() {
	
	Unigine::GuiPtr GUI = Unigine::Gui::getCurrent();

	if (GUI->isChild(AsyncLabel)) GUI->removeChild(AsyncLabel);
	if (GUI->isChild(UpdateLabel)) GUI->removeChild(UpdateLabel);
	if (GUI->isChild(PhysicsLabel)) GUI->removeChild(PhysicsLabel);
	if (GUI->isChild(StartAnim)) GUI->removeChild(StartAnim);


	AsyncLabel.deleteLater();
	UpdateLabel.deleteLater();
	PhysicsLabel.deleteLater();
	StartAnim.deleteLater();
}

void TimeController::nodeects() {

	Time += Unigine::Game::getIFps();
	float t = Time / TimeSlider->getValue();
	Unigine::Math::Vec3 Pos;

	Pos = Lerper::Lerp(Starts[0], Starts[0] + End, t, Lerper::LINEAR);
	Objects[0]->setWorldPosition(Pos);

	Pos = Lerper::Lerp(Starts[1], Starts[1] + End, t, Lerper::EASE_IN);
	Objects[1]->setWorldPosition(Pos);


	Pos = Lerper::Lerp(Starts[2], Starts[2] + End, t, Lerper::EASE_OUT);
	Objects[2]->setWorldPosition(Pos);


	Pos = Lerper::Lerp(Starts[3], Starts[3] + End, t, Lerper::EASE_IN_OUT);
	Objects[3]->setWorldPosition(Pos);

	Pos = Lerper::PingPong(Starts[4], Starts[4] + End, t, 1);
	Objects[4]->setWorldPosition(Pos);

	float tCurve = Curve->evaluate(t);	
	Pos = Lerper::Lerp(Starts[5], Starts[5] + End, tCurve, Lerper::LINEAR);
	Objects[5]->setWorldPosition(Pos);

	if (t > 1.0f) { Time = 0; canAnimate = 0; }
}