#ifndef UTILITY_HELPER_H
#define UTILITY_HELPER_H
#include <mutex>
#include <atomic>

class Helper
{
public:
	~Helper();
	static Helper* instance();

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
	Helper();
	static std::recursive_mutex m_mutex;
	static std::atomic<Helper*> m_helper;
};

#endif // UTILITY_HELPER_H
