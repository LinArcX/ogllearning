#ifndef APP_STATE_EXIT_H
#define APP_STATE_EXIT_H

#include <mutex>
#include <atomic>
#include "state.hpp"

namespace ogl {
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
}
#endif
