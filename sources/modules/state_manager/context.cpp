#include "context.hpp"

ogl::Context::Context() {}

ogl::Context::~Context()
{
	if (m_state) {
		delete m_state;
	}
}

void ogl::Context::setState(State* const state)
{
	//if (state) {
	//	delete state;
	//}
	m_state = state;
}

void ogl::Context::request()
{
	m_state->action();
}

std::recursive_mutex ogl::Context::m_mutex;
std::atomic<ogl::Context*> ogl::Context::m_context = nullptr;

ogl::Context* ogl::Context::instance()
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
