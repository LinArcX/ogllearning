#include "Exit.hpp"

#include <iostream>

using namespace ogl::state::application;

Exit::Exit() {}

std::recursive_mutex Exit::m_mutex;
std::atomic<Exit*> Exit::m_exit = nullptr;

Exit* Exit::instance()
{
	auto object = m_exit.load(std::memory_order_relaxed);
	atomic_thread_fence(std::memory_order_acquire);
	if (!object)
	{
		std::lock_guard<std::recursive_mutex> lock(m_mutex);
		object = m_exit.load(std::memory_order_relaxed);
		if (!object)
		{
			object = new Exit;
			std::atomic_thread_fence(std::memory_order_release);
			m_exit.store(object, std::memory_order_relaxed);
		}
	}
	return object;
}

void Exit::action()
{
	std::cout << "Exit!" << std::endl;
}
