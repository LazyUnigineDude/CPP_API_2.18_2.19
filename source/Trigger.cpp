#include "Trigger.h"
REGISTER_COMPONENT(Trigger);

void Trigger::Init() {

	Unigine::Log::message("Hi\n");
	//_WT = Unigine::static_ptr_cast<Unigine::WorldTrigger>(WTNode.get());
	//
	//_WT->renderVisualizer();
	//_WT->getEventEnter().connect(EC, this, &Trigger::Enter);
	//_WT->getEventLeave().connect(LC, this, &Trigger::Leave);
}

void Trigger::Shutdown()
{
}


void Trigger::Enter(const Unigine::NodePtr& Obj) {
	Unigine::Log::message("Object Entered: %s\n", Obj->getName());
}

void Trigger::Leave(const Unigine::NodePtr& Obj) {
	Unigine::Log::message("Object Left: %s\n", Obj->getName());
}