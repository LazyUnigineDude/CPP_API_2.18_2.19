#include "Camera.h"
REGISTER_COMPONENT(CameraDetect);

void CameraDetect::Init() {

	Camera = Unigine::static_ptr_cast<Unigine::Player>(CameraNode.get());
}

void CameraDetect::Update() {

	SetPoints(Unigine::Math::AXIS_NZ, 2, CameraNode);
	Unigine::Visualizer::renderVector(P0, P1, Unigine::Math::vec4_black);
	Unigine::Visualizer::renderFrustum(Camera->getProjection(), Camera->getWorldTransform(), Unigine::Math::vec4_white);

}

