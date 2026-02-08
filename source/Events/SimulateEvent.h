#pragma once
#include "EventHandler.h"

class SimulateEvent : public Unigine::ComponentBase {
public:

	COMPONENT_DEFINE(SimulateEvent, ComponentBase);
	COMPONENT_INIT(Init);
	COMPONENT_UPDATE(Update);
	COMPONENT_SHUTDOWN(Shutdown);

protected:
	void Init();
	void Update();
	void Shutdown();

private:
    AchievementEventHandler ASys;
	DamageEventHandler DSys;
};