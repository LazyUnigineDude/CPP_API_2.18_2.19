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
	PROP_PARAM(Node, NTNode)
	PROP_PARAM(Node, PTNode)
	void Init(), Update(), Shutdown();

	//void Enter(const Unigine::NodePtr& Obj), Leave(const Unigine::NodePtr& Obj);

private:
	Unigine::NodeTriggerPtr _NT;
	Unigine::PhysicalTriggerPtr _PT;
	Unigine::WorldTriggerPtr _WT;
	Unigine::EventConnections EC, LC;

	void Move(const Unigine::NodeTriggerPtr& Obj);
	Unigine::WidgetLabelPtr Label;
};