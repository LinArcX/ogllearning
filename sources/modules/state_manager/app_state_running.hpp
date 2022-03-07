#ifndef APP_STATE_RUNNING_H
#define APP_STATE_RUNNING_H

#include <mutex>
#include <atomic>
#include "state.hpp"

namespace ogl {
	class AppStateRunning : public State {
	public:
		~AppStateRunning() { ; }
		static AppStateRunning* instance();

		void action();

	private:
		AppStateRunning();
		static std::recursive_mutex m_mutex;
		static std::atomic<AppStateRunning*> m_app_state_running;
	};
}
#endif
