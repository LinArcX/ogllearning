#pragma once
#include "State.hpp"
#include <mutex>
#include <atomic>

class AppStateRunning : public State {
public:
	~AppStateRunning() {}
	static AppStateRunning* instance();

	void action();

private:
	AppStateRunning();
	static std::recursive_mutex m_mutex;
	static std::atomic<AppStateRunning*> m_app_state_running;
};


