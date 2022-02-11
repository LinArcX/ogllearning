#include "app_state_running.hpp"

#include <iostream>

std::recursive_mutex AppStateRunning::m_mutex;
std::atomic<AppStateRunning*> AppStateRunning::m_app_state_running = nullptr;

AppStateRunning* AppStateRunning::instance()
{
	auto object = m_app_state_running.load(std::memory_order_relaxed);
	atomic_thread_fence(std::memory_order_acquire);
	if (!object)
	{
		std::lock_guard<std::recursive_mutex> lock(m_mutex);
		object = m_app_state_running.load(std::memory_order_relaxed);
		if (!object)
		{
			object = new AppStateRunning;
			std::atomic_thread_fence(std::memory_order_release);
			m_app_state_running.store(object, std::memory_order_relaxed);
		}
	}
	return object;
}

void AppStateRunning::action()
{
	std::cout << "Running.." << std::endl;
}

AppStateRunning::AppStateRunning()
{
}
