#pragma once
#include "Simple.h"

struct CameraDetect : public SimpleDetect {

public:
	COMPONENT_DEFINE(CameraDetect, SimpleDetect);
	COMPONENT_INIT(Init);
	COMPONENT_UPDATE(Update);


protected:
	void Init(), Update();
	PROP_PARAM(Node, CameraNode);
	Unigine::PlayerPtr Camera;
};
