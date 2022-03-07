#include "type_utility.hpp"
#include <type_traits>

std::recursive_mutex ogl::TypeUtility::m_mutex;
std::atomic<ogl::TypeUtility*> ogl::TypeUtility::m_type_utility = nullptr;

ogl::TypeUtility::TypeUtility() {}

ogl::TypeUtility::~TypeUtility() {}

ogl::TypeUtility* ogl::TypeUtility::instance()
{
	auto object = m_type_utility.load(std::memory_order_relaxed);
	atomic_thread_fence(std::memory_order_acquire);
	if (!object)
	{
		std::lock_guard<std::recursive_mutex> lock(m_mutex);
		object = m_type_utility.load(std::memory_order_relaxed);
		if (!object)
		{
			object = new ogl::TypeUtility;
			std::atomic_thread_fence(std::memory_order_release);
			m_type_utility.store(object, std::memory_order_relaxed);
		}
	}
	return object;
}
