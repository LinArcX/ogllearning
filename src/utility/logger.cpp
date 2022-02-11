#include "logger.hpp"
#include "../window_manager/window_manager_glfw.hpp"
#include "../window_manager/window_manager_sdl.hpp"

std::recursive_mutex Logger::m_mutex;
std::atomic<Logger*> Logger::m_logger = nullptr;

Logger::Logger()
{}

Logger::~Logger()
{}

Logger* Logger::instance()
{
	auto object = m_logger.load(std::memory_order_relaxed);
	atomic_thread_fence(std::memory_order_acquire);
	if (!object)
	{
		std::lock_guard<std::recursive_mutex> lock(m_mutex);
		object = m_logger.load(std::memory_order_relaxed);
		if (!object)
		{
			object = new Logger;
			std::atomic_thread_fence(std::memory_order_release);
			m_logger.store(object, std::memory_order_relaxed);
		}
	}
	return object;
}
