#include "Running.hpp"

#include <iostream>

using namespace ogl::state::application;

std::recursive_mutex Running::m_mutex;
std::atomic<Running*> Running::m_running = nullptr;

Running::Running() {}

Running* Running::instance()
{
	auto object = m_running.load(std::memory_order_relaxed);
	atomic_thread_fence(std::memory_order_acquire);
	if (!object)
	{
		std::lock_guard<std::recursive_mutex> lock(m_mutex);
		object = m_running.load(std::memory_order_relaxed);
		if (!object)
		{
			object = new Running;
			std::atomic_thread_fence(std::memory_order_release);
			m_running.store(object, std::memory_order_relaxed);
		}
	}
	return object;
}

void Running::action()
{
	std::cout << "Running.." << std::endl;
}
