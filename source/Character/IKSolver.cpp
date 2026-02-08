#include "IKSolver.h"
REGISTER_COMPONENT(IKSolver);

void IKSolver::Init() {

	Ptr = Unigine::WorldIntersectionNormal::create();

	Animation = Unigine::static_ptr_cast<Unigine::ObjectMeshSkinned>(node);

	IKLeft = Animation->addIKChain();
	for (int i = 0; i < LLeg.size(); i++) 
		Animation->addIKChainBone(LLeg[i], IKLeft);


	IKRight = Animation->addIKChain();
	for (int i = 0; i < RLeg.size(); i++)
		Animation->addIKChainBone(RLeg[i], IKRight);

	Animation->addVisualizeIKChain(IKLeft);
	Animation->addVisualizeIKChain(IKRight);
}

void IKSolver::Update() {

	Animation->setIKChainPoleWorldPosition(node->getChild(0)->getWorldPosition(), IKLeft);
	Animation->setIKChainPoleWorldPosition(node->getChild(1)->getWorldPosition(), IKRight);

	AlignFoot(Animation->getBoneWorldTransform(LLeg[1]), IKLeft);
	AlignFoot(Animation->getBoneWorldTransform(RLeg[1]), IKRight);

}

void IKSolver::Shutdown() {

	if (Ptr) Ptr.~Ptr();
}

void IKSolver::AlignFoot(const Unigine::Math::Mat4& BoneTransform, const int& BoneNum) {

	Unigine::ObjectPtr Obj = Unigine::World::getIntersection(BoneTransform.getTranslate(), BoneTransform.getTranslate() + Unigine::Math::Vec3_down * 5, GroundMask, Ptr);
	if (!Obj) return;

	Unigine::Math::Vec3 Pos{ Ptr->getPoint() };
	Unigine::Math::quat Rot{ BoneTransform.getRotate() };

	Unigine::Math::vec3 Nor{ Ptr->getNormal()};
	Rot = Unigine::Math::rotationFromTo(Unigine::Math::vec3_up, Nor) * Rot;

	Animation->setIKChainTargetWorldPosition(Pos + (Unigine::Math::Vec3_up * AnkleHeight), BoneNum);
	Animation->setIKChainEffectorWorldRotation(Rot, BoneNum);
}