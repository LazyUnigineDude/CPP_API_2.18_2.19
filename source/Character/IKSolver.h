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
	PROP_PARAM(Mask, GroundMask);
	PROP_PARAM(Float, AnkleHeight, 1.0f);
	PROP_ARRAY(Int, LLeg);
	PROP_ARRAY(Int, RLeg);
	void Init(), Update(), Shutdown();

private:
	int IKLeft, IKRight;
	Unigine::ObjectMeshSkinnedPtr Animation;
	void AlignFoot(const Unigine::Math::Mat4& BoneTransform, const int& BoneNum);
	Unigine::WorldIntersectionNormalPtr Ptr;
};