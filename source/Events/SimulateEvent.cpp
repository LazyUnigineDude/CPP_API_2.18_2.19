#include "SimulateEvent.h"
REGISTER_COMPONENT(SimulateEvent);

void SimulateEvent::Init() {

	ASys.Init();
	DSys.Init();

}

void SimulateEvent::Update()
{
	if (Unigine::Input::isKeyDown(Unigine::Input::KEY_U)) { 
		auto& EManager = EventManager::instance(); 
		EManager.Achievement.RunEvent(ACHIEVEMENTS_EVENT::EVENT_CLEARED); 
	}

	if (Unigine::Input::isKeyDown(Unigine::Input::KEY_I)) {
		auto& EManager = EventManager::instance();
		EManager.Achievement.RunEvent(ACHIEVEMENTS_EVENT::HIDDEN_EVENT_CLEARED);
	}

	if (Unigine::Input::isKeyDown(Unigine::Input::KEY_O)) {
		auto& EManager = EventManager::instance();
		EManager.State.RunEvent(PLAYER_STATE_EVENT::POISONED);
	}
}

void SimulateEvent::Shutdown()
{

}
