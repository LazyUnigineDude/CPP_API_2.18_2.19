#pragma once
#include <Unigine.h>

struct TriggerExample : public Unigine::ComponentBase {

public:
	COMPONENT_DEFINE(TriggerExample, ComponentBase);
	COMPONENT_INIT(Init);
	COMPONENT_UPDATE(Update);
	COMPONENT_SHUTDOWN(Shutdown);

protected:
	PROP_PARAM(Node, WTNode)
	void Init(), Update(), Shutdown();

	//void Enter(const Unigine::NodePtr& Obj), Leave(const Unigine::NodePtr& Obj);

private:
	Unigine::WorldTriggerPtr _WT;
};