#include "context.hpp"

std::recursive_mutex Context::m_mutex;
std::atomic<Context*> Context::m_context = nullptr;

Context::~Context()
{
	if (state) {
		delete state;
	}
}

Context* Context::instance()
{
	auto object = m_context.load(std::memory_order_relaxed);
	atomic_thread_fence(std::memory_order_acquire);
	if (!object)
	{
		std::lock_guard<std::recursive_mutex> lock(m_mutex);
		object = m_context.load(std::memory_order_relaxed);
		if (!object)
		{
			object = new Context;
			std::atomic_thread_fence(std::memory_order_release);
			m_context.store(object, std::memory_order_relaxed);
		}
	}
	return object;
}

void Context::setState(State* const s)
{
	//if (state) {
	//	delete state;
	//}
	state = s;
}

void Context::request()
{
	state->action();
}

Context::Context()
{
}
