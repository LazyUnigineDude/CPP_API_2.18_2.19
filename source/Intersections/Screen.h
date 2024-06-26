#pragma once
#include "Camera.h"
#include <UnigineGame.h>

struct ScreenDetect : public CameraDetect {

public:
	COMPONENT_DEFINE(ScreenDetect, CameraDetect);
	COMPONENT_INIT(Init);
	COMPONENT_UPDATE(Update);

protected:
	void Init(), Update();
	PROP_PARAM(Mask, GroundMask, 0x01);

};