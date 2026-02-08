#pragma once
#include "unigine.h"
#include "Events.h"

class AchievementEventHandler {
public:

	AchievementEventHandler() {}

	virtual void Init() {
		auto& EManager = EventManager::instance();

		EManager.Achievement.Subscription().connect(
			connection,
			// Logic Here
			[this](ACHIEVEMENTS_EVENT e) {
				if (e == ACHIEVEMENTS_EVENT::EVENT_CLEARED) {
					Unigine::Log::message("Achievement cleared!\n");
					connection.disconnect();
				}
			}
		);

		EManager.Achievement.Subscription().connect(
			connection2,
			// Logic Here
			[this](ACHIEVEMENTS_EVENT e) {
				if (e == ACHIEVEMENTS_EVENT::HIDDEN_EVENT_CLEARED) {
					Unigine::Log::message("Hidden cleared!\n");
					connection2.disconnect();
				}
			}
		);

	}

private:
	Unigine::EventConnection connection, connection2;
};

class DamageEventHandler {
public:
	DamageEventHandler() {}

	virtual void Init() {
		auto& EManager = EventManager::instance();

		EManager.State.Subscription().connect(
			connection,
			[this](PLAYER_STATE_EVENT e) {

				if (e == PLAYER_STATE_EVENT::POISONED) {
					HealthDmg(2);
					Unigine::Log::message("You've Been Poisoned! Health now %d\n", PlayerHealth);
				}

				if (e == PLAYER_STATE_EVENT::DEAD) {
					Unigine::Log::message("You Dead!\n");
					connection.disconnect();
				}
			}
		);
	}


private:
	Unigine::EventConnection connection;
	int PlayerHealth = 10;

	void HealthDmg(int val) {
		auto& EManager = EventManager::instance();
		PlayerHealth -= 2;
		EManager.Damage.RunEvent(DAMAGE_EVENT(2));

		if (PlayerHealth <= 0) EManager.State.RunEvent(PLAYER_STATE_EVENT::DEAD);
	}
};