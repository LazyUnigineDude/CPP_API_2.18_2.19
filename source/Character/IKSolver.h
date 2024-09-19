#pragma once
#include <UnigineObjects.h>
#include <UnigineComponentSystem.h>
#include <UnigineVisualizer.h>

struct IKSolver : public Unigine::ComponentBase {

public:
	COMPONENT_DEFINE(IKSolver, ComponentBase);
	COMPONENT_INIT(Init);
	COMPONENT_UPDATE(Update);
	COMPONENT_SHUTDOWN(Shutdown);

protected:
	PROP_ARRAY(Int, LLeg);
	PROP_ARRAY(Int, RLeg);
	void Init(), Update(), Shutdown();
};