#ifndef UTILITY_LOGGER_H
#define UTILITY_LOGGER_H
#include <mutex>
#include <atomic>
#include <iostream>
#include "../window_manager/window_manager.hpp"

class Logger
{
public:
	~Logger();
	static Logger* instance();
	void set_window_manager(IWindowManager& window_manager);

	template <typename T>
	void fatal_error(T t)
	{
		std::cout << t << std::endl;
		std::cout << "Enter any key to quit...";
		int temp;
		std::cin >> temp;
	}

	template<typename T, typename... Args>
	void fatal_error(T t, Args... args)
	{
		std::cout << t << std::endl;
		fatal_error(args...);
		m_window_manager->release_resources();
		exit(-1);
	}

private:
	Logger();
	static std::recursive_mutex m_mutex;
	static std::atomic<Logger*> m_logger;
  IWindowManager* m_window_manager = nullptr;
};
#endif //UTILITY_LOGGER_H
