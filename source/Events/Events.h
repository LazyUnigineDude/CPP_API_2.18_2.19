#pragma once
#include <Unigine.h>

enum class ACHIEVEMENTS_EVENT {
    EVENT_CLEARED,
    HIDDEN_EVENT_CLEARED
};

enum class PLAYER_STATE_EVENT {
    NORMAL,
    POISONED,
    DEAD
};

struct DAMAGE_EVENT {
    DAMAGE_EVENT(int a) { amount = a; }
    int amount;
};

template<typename T>
class Event {
public:
    Unigine::Event<T>& Subscription() { return EventRunner; }
    void RunEvent(const T& Val) { EventRunner.run(Val); }

private:
    Unigine::EventInvoker<T> EventRunner;
};

class EventManager {
public:
    static EventManager& instance() {
        static EventManager inst;
        return inst;
    }

    Event<ACHIEVEMENTS_EVENT> Achievement;
    Event<PLAYER_STATE_EVENT> State;
    Event<DAMAGE_EVENT> Damage;

private:
    EventManager() = default;
    ~EventManager() = default;

    EventManager(const EventManager&) = delete;
    EventManager& operator=(const EventManager&) = delete;
};