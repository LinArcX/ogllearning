#ifndef TYPE_UTILITY_H
#define TYPE_UTILITY_H

#include <mutex>
#include <atomic>

namespace ogl {
	class TypeUtility
	{
	public:
		~TypeUtility();
		static TypeUtility* instance();

		template <class DstType, class SrcType>
		bool IsType(const SrcType* src)
		{
			return dynamic_cast<const DstType*>(src) != nullptr;
		}

		template <typename Base, typename T>
		inline bool instanceof(const T*) {
			return std::is_base_of<Base, T>::value;
		}

	private:
		TypeUtility();

		static std::recursive_mutex m_mutex;
		static std::atomic<TypeUtility*> m_type_utility;
	};
}
#endif
