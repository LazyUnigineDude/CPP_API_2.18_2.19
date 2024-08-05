#pragma once
#include <UnigineComponentSystem.h>
#include <UnigineWidgets.h>

struct Widgets : public Unigine::ComponentBase {

public:
	COMPONENT_DEFINE(Widgets, ComponentBase);
	COMPONENT_INIT(Init);
	COMPONENT_SHUTDOWN(Shutdown);

protected:
	void Init(), Shutdown();

private:

};