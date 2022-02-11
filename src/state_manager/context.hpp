#pragma once
#include <mutex>
#include <atomic>
//#include <cstdlib>
#include "State.hpp"

class Context
{
public:
	~Context();
	static Context* instance();

	void request();
	void setState(State* const s);
	State* getState() { return state; }

private:
	Context();
	State* state;
	static std::recursive_mutex m_mutex;
	static std::atomic<Context*> m_context;
};
