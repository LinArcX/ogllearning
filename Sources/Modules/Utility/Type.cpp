#include "Type.hpp"

#include <type_traits>

using namespace ogl::utility;

std::recursive_mutex Type::m_mutex;
std::atomic<Type*> Type::m_type = nullptr;

Type::Type() {}

Type::~Type() {}

Type* Type::instance()
{
	auto object = m_type.load(std::memory_order_relaxed);
	atomic_thread_fence(std::memory_order_acquire);
	if (!object)
	{
		std::lock_guard<std::recursive_mutex> lock(m_mutex);
		object = m_type.load(std::memory_order_relaxed);
		if (!object)
		{
			object = new Type;
			std::atomic_thread_fence(std::memory_order_release);
			m_type.store(object, std::memory_order_relaxed);
		}
	}
	return object;
}
