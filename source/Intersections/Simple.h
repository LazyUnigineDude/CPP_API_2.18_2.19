#pragma once
#include <UnigineWorld.h>
#include <UnigineComponentSystem.h>

struct SimpleDetect : public Unigine::ComponentBase {

public:
	COMPONENT_DEFINE(SimpleDetect, ComponentBase);
	COMPONENT_INIT(Init);
	COMPONENT_UPDATE(Update);

protected:
	void Init(), Update();

private:
	Unigine::WorldIntersectionPtr Ptr;

};