#include "ComponentCheck.h"
REGISTER_COMPONENT(ComponentCheck)
REGISTER_COMPONENT(DerivedComponentCheck)

void ComponentCheck::Init() { Unigine::Log::message("Base Init\n");

clutter = Unigine::ObjectMeshClutter::create(Data);
clutter->setWorldPosition(Unigine::Math::Vec3_zero);
clutter->setSizeX(5);
clutter->setSizeY(5);

}
void ComponentCheck::UpdateAsync() { }
void ComponentCheck::UpdateSync() { }
void ComponentCheck::Update() { }
void ComponentCheck::UpdatePost() { }
void ComponentCheck::UpdatePhysics() { }
void ComponentCheck::Swap() { }
void ComponentCheck::Shutdown() { }

void DerivedComponentCheck::Init() { Unigine::Log::message("Derived Init\n"); }