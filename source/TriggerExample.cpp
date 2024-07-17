#include "TriggerExample.h"
REGISTER_COMPONENT(TriggerExample);


static void Enter(const Unigine::NodePtr& Obj) {
	Unigine::Log::message("Object Entered: %s\n", Obj->getName());
}

static void Leave(const Unigine::NodePtr& Obj) {
	Unigine::Log::message("Object Left: %s\n", Obj->getName());
}

void TriggerExample::Init() {

	Unigine::Log::message("Hi\n");
	_WT = Unigine::static_ptr_cast<Unigine::WorldTrigger>(WTNode.get());

	if (_WT) {
		_WT->getEventEnter().connect(&Enter);
		_WT->getEventLeave().connect(&Leave);
	}  
}

void TriggerExample::Update() {
	if (_WT) _WT->renderVisualizer();
}

void TriggerExample::Shutdown()
{
}