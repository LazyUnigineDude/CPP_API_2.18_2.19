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
		PROP_ARRAY(Node, Objects)

private:
	void Init(), UpdateAsync(), Update(), UpdatePhysics(), Shutdown();
	void MoveObjects();

	Unigine::WidgetLabelPtr AsyncLabel, UpdateLabel, PhysicsLabel;
	Unigine::WidgetSliderPtr TimeSlider;
	float Time;
	Unigine::Vector<Unigine::Math::Vec3> Starts;
	Unigine::Math::Vec3 End = Unigine::Math::Vec3_left * -4;
};

std::string FloatToString(float value, int percision = 8) {
	std::ostringstream stream;
	stream << std::fixed << std::setprecision(percision) << value;
	return stream.str();
}


struct Lerper {

public:
	enum LERP_TYPE { LINEAR, EASE_IN, EASE_OUT, EASE_IN_OUT };
	static Unigine::Math::Vec3 Lerp(
		Unigine::Math::Vec3 Start,
		Unigine::Math::Vec3 End,
		float T,
		LERP_TYPE TYPE = LINEAR);

private:
	static Unigine::Math::Vec3 MLerp(
		Unigine::Math::Vec3 Start,
		Unigine::Math::Vec3 End,
		float T) {
		return Unigine::Math::Vec3(
			Lerp(Start.x, End.x, T),
			Lerp(Start.y, End.y, T),
			Lerp(Start.z, End.z, T)
		);
	}

	static float Lerp(float s, float e, float t) { return s + (e - s) * t; }
	static float EIn(float T) { return T * T; }
	static float EOut(float T) { return Flip(Squared(Flip(T))); }
	static float EInOut(float T) { return Unigine::Math::lerp(EIn(T), EOut(T), T); }
	static float Spike(float T) { if (T <= 0.5f) return EIn(T * 2); return EIn(Flip(T) * 2); }


	static float Flip(float x) { return 1 - x; }
	static float Squared(float x) { return x * x; }

};

inline Unigine::Math::Vec3 Lerper::Lerp(
	Unigine::Math::Vec3 Start,
	Unigine::Math::Vec3 End,
	float T,
	LERP_TYPE TYPE) {

	switch (TYPE) {
	case Lerper::EASE_IN:		return MLerp(Start, End, EIn(T));
	case Lerper::EASE_OUT:		return MLerp(Start, End, EOut(T));
	case Lerper::EASE_IN_OUT:	return MLerp(Start, End, EInOut(T));
	default: return MLerp(Start, End, T);
	}
}