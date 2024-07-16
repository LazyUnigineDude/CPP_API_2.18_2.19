#pragma once
#include <UnigineComponentSystem.h>
#include <UnigineWorlds.h>

struct Trigger : public Unigine::ComponentBase {

public:
	COMPONENT_DEFINE(Trigger, ComponentBase);
	COMPONENT_INIT(Init);
	COMPONENT_SHUTDOWN(Shutdown);

protected:
	PROP_PARAM(Node, WTNode)
	void Init(), Shutdown();

	void Enter(const Unigine::NodePtr& Obj), Leave(const Unigine::NodePtr& Obj);

private:
	Unigine::WorldTriggerPtr _WT;
	Unigine::EventConnections EC, LC;
};