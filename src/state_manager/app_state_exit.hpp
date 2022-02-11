#pragma once
#include "State.hpp"
#include <mutex>
#include <atomic>

class AppStateExit : public State {
public:
	~AppStateExit() {}
	static AppStateExit* instance();
	void action();

private:
	AppStateExit();
	static std::recursive_mutex m_mutex;
	static std::atomic<AppStateExit*> m_app_state_exit;
};
