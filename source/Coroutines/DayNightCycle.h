#pragma once
#include <Unigine.h>

struct DayNightCycle : public Unigine::ComponentBase {

public:
	COMPONENT_DEFINE(DayNightCycle, ComponentBase);
	COMPONENT_INIT(Init);
	COMPONENT_UPDATE(Update);
	COMPONENT_SHUTDOWN(Shutdown);

	PROP_PARAM(Node, SunNode);
	PROP_PARAM(Node, MoonNode);
	PROP_PARAM(Curve2d, Curve);
	PROP_PARAM(Float, CycleTimeMin, 1);

protected:
	void Init(), Update(), Shutdown();

private:
	int SunInit{ 270 }, MoonInit{ 90 };
	float Cycling{1};
};