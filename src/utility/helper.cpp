#include "helper.hpp"
std::recursive_mutex Helper::m_mutex;
std::atomic<Helper*> Helper::m_helper = nullptr;

Helper::~Helper()
{
}

Helper* Helper::instance()
{
	auto object = m_helper.load(std::memory_order_relaxed);
	atomic_thread_fence(std::memory_order_acquire);
	if (!object)
	{
		std::lock_guard<std::recursive_mutex> lock(m_mutex);
		object = m_helper.load(std::memory_order_relaxed);
		if (!object)
		{
			object = new Helper;
			std::atomic_thread_fence(std::memory_order_release);
			m_helper.store(object, std::memory_order_relaxed);
		}
	}
	return object;
}

Helper::Helper()
{
}
