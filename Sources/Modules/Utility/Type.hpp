#ifndef UTILITY_TYPE_H
#define UTILITY_TYPE_H

#include <mutex>
#include <atomic>

namespace ogl {
	namespace utility {
		class Type
		{
		public:
			~Type();
			static Type* instance();

			template <class DstType, class SrcType>
			bool sameType(const SrcType* src)
			{
				return dynamic_cast<const DstType*>(src) != nullptr;
			}

			template <typename Base, typename T>
			inline bool instanceOf(const T*) {
				return std::is_base_of<Base, T>::value;
			}

		private:
			Type();

			static std::recursive_mutex m_mutex;
			static std::atomic<Type*> m_type;
		};
	}
}
#endif
