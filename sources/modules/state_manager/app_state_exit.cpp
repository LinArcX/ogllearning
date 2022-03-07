#include "app_state_exit.hpp"
#include <iostream>

ogl::AppStateExit::AppStateExit() {}

std::recursive_mutex ogl::AppStateExit::m_mutex;
std::atomic<ogl::AppStateExit*> ogl::AppStateExit::m_app_state_exit = nullptr;

ogl::AppStateExit* ogl::AppStateExit::instance()
{
	auto object = m_app_state_exit.load(std::memory_order_relaxed);
	atomic_thread_fence(std::memory_order_acquire);
	if (!object)
	{
		std::lock_guard<std::recursive_mutex> lock(m_mutex);
		object = m_app_state_exit.load(std::memory_order_relaxed);
		if (!object)
		{
			object = new AppStateExit;
			std::atomic_thread_fence(std::memory_order_release);
			m_app_state_exit.store(object, std::memory_order_relaxed);
		}
	}
	return object;
}

void ogl::AppStateExit::action()
{
	std::cout << "Exit!" << std::endl;
}
