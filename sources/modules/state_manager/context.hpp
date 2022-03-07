#ifndef CONTEXT_H
#define CONTEXT_H

#include <mutex>
#include <atomic>
#include "state.hpp"

namespace ogl {
	class Context
	{
	public:
		~Context();

		static Context* instance();
		void request();

		static void setState(State* const state);
		static State* getState() { return m_state; }

	private:
		Context();

		inline static State* m_state;
		static std::recursive_mutex m_mutex;
		static std::atomic<Context*> m_context;
	};
}
#endif
