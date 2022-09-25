#ifndef STATE_APPLICAITON_RUNNING_H
#define STATE_APPLICAITON_RUNNING_H

#include <mutex>
#include <atomic>
#include "../State.hpp"

namespace ogl {
	namespace state {
		namespace application {
			class Running : public State {
			public:
				~Running() { ; }
				static Running* instance();

				void action();

			private:
				Running();
				static std::recursive_mutex m_mutex;
				static std::atomic<Running*> m_running;
			};
		}
	}
}
#endif
