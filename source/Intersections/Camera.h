#pragma once
#include "Simple.h"

struct CameraDetect : public SimpleDetect {

public:
	COMPONENT_DEFINE(CameraDetect, SimpleDetect);
	COMPONENT_INIT(Init);
	COMPONENT_UPDATE(Update);
	COMPONENT_SHUTDOWN(Shutdown);


protected:
	void Init(), Update(), Shutdown();
	PROP_PARAM(Node, CameraNode);

private:
	Unigine::PlayerPtr Camera;
};
