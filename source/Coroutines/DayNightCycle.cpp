#include "DayNightCycle.h"
REGISTER_COMPONENT(DayNightCycle)

void DayNightCycle::Init() { Cycling = 1 / CycleTimeMin; }

void DayNightCycle::Update() {

	float CurveVal = Curve->evaluate(Unigine::Game::getTime() * Cycling);
	SunNode ->setWorldRotation(Unigine::Math::quat(SunInit  + CurveVal, 0, 0));
	MoonNode->setWorldRotation(Unigine::Math::quat(MoonInit + CurveVal, 0, 0));

}

void DayNightCycle::Shutdown() {

}
