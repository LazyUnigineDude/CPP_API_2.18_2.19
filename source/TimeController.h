#pragma once
#include <UnigineComponentSystem.h>
#include <UnigineGame.h>
#include <UnigineAsyncQueue.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

class TimeController : public Unigine::ComponentBase {

public:
	COMPONENT_DEFINE(TimeController, ComponentBase)
		COMPONENT_INIT(Init)
		COMPONENT_UPDATE(Update)
		COMPONENT_UPDATE_PHYSICS(UpdatePhysics)
		COMPONENT_UPDATE_ASYNC_THREAD(UpdateAsync)
		COMPONENT_SHUTDOWN(Shutdown)

private:
	void Init(), UpdateAsync(), Update(), UpdatePhysics(), Shutdown();
	void MoveObject();

	Unigine::WidgetLabelPtr AsyncLabel, UpdateLabel, PhysicsLabel;
	Unigine::WidgetSliderPtr TimeSlider;
	float Time;
};

std::string FloatToString(float value, int percision = 8) {
	std::ostringstream stream;
	stream << std::fixed << std::setprecision(percision) << value;
	return stream.str();
}

