#ifndef STATE_APPLICATION_EXIT_H
#define STATE_APPLICATION_EXIT_H

#include <mutex>
#include <atomic>

#include "../State.hpp"

namespace ogl {
	namespace state {
		namespace application {
			class Exit : public State {
			public:
				~Exit() {}

				static Exit* instance();

				void action();

			private:
				Exit();
				static std::recursive_mutex m_mutex;
				static std::atomic<Exit*> m_exit;
			};
		}
	}
}
#endif
