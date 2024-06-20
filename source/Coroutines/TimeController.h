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
		PROP_PARAM(Curve2d, Curve)

private:
	void Init(), UpdateAsync(), Update(), UpdatePhysics(), Shutdown();
	void nodeects();

	Unigine::WidgetLabelPtr AsyncLabel, UpdateLabel, PhysicsLabel;
	Unigine::WidgetSliderPtr TimeSlider;
	Unigine::WidgetButtonPtr StartAnim;
	float Time;
	bool canAnimate = 0;
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
		const Unigine::Math::Vec3& Start,
		const Unigine::Math::Vec3& End,
		const float& T,
		LERP_TYPE TYPE = LINEAR);
	
	static Unigine::Math::Vec3 PingPong(
		const Unigine::Math::Vec3& Start,
		const Unigine::Math::Vec3& End,
		const float& T,
		const int& repeat
	);

private:
	static Unigine::Math::Vec3 MLerp(
		Unigine::Math::Vec3 Start,
		Unigine::Math::Vec3 End,
		const float& T) {
		return Unigine::Math::Vec3(
			Lerp(Start.x, End.x, T),
			Lerp(Start.y, End.y, T),
			Lerp(Start.z, End.z, T)
		);
	}

	static float Lerp(const float& s, const float& e, const float& t) { return s + (e - s) * t; }
	static float EIn(const float& T) { return Squared(T); }
	static float EOut(const float& T) { return Flip(Squared(Flip(T))); }
	static float EInOut(const float& T) { return Unigine::Math::lerp(EIn(T), EOut(T), T); }
	static float pingPong(const double& min, const double& max,const float& t, const int& repeat) {
		double hRepeat = repeat * 0.5;
		double phase = t / repeat;
		double slope = (max - min) / hRepeat;

		if (phase < hRepeat) { return min + (slope * phase); }
		return max - (slope * (phase - hRepeat));
	}

	static float Flip(const float& t) { return 1 - t; }
	static float Squared(const float& t) { return t * t; }
};

inline Unigine::Math::Vec3 Lerper::Lerp(
	const Unigine::Math::Vec3& Start,
	const Unigine::Math::Vec3& End,
	const float& T,
	LERP_TYPE TYPE) {

	switch (TYPE) {
	case Lerper::EASE_IN:		return MLerp(Start, End, EIn(T));
	case Lerper::EASE_OUT:		return MLerp(Start, End, EOut(T));
	case Lerper::EASE_IN_OUT:	return MLerp(Start, End, EInOut(T));
	default:					return MLerp(Start, End, T);
	}
}

inline Unigine::Math::Vec3 Lerper::PingPong(
	const Unigine::Math::Vec3& Start,
	const Unigine::Math::Vec3& End,
	const float& t,
	const int& repeat) {

	return Unigine::Math::Vec3(
		pingPong(Start.x, End.x, t, repeat),
		pingPong(Start.y, End.y, t, repeat),
		pingPong(Start.z, End.z, t, repeat)
	);
}