#include "io_manager.hpp"

std::recursive_mutex IOManager::m_mutex;
std::atomic<IOManager*> IOManager::m_io_manager = nullptr;

IOManager::~IOManager()
{
}

IOManager * IOManager::instance()
{
	auto object = m_io_manager.load(std::memory_order_relaxed);
	atomic_thread_fence(std::memory_order_acquire);
	if (!object)
	{
		std::lock_guard<std::recursive_mutex> lock(m_mutex);
		object = m_io_manager.load(std::memory_order_relaxed);
		if (!object)
		{
			object = new IOManager;
			std::atomic_thread_fence(std::memory_order_release);
			m_io_manager.store(object, std::memory_order_relaxed);
		}
	}
	return object;
}

bool IOManager::read_file_to_buffer(std::string file_path, std::vector<char>& buffer)
{
	std::ifstream file(file_path, std::ios::binary);
	if (file.fail())
	{
		perror(file_path.c_str());
		return false;
	}

	std::streamoff fsize = file_size(file);
	buffer.resize((size_t)fsize);
	file.read(&(buffer[0]), fsize);
	file.close();
	return true;
}

std::streamoff IOManager::file_size(std::ifstream& file)
{
	file.seekg(0, std::ios::end);
	std::streamoff file_size = file.tellg();

	file.seekg(0, std::ios::beg);
	file_size -= file.tellg();

	return file_size;
}

IOManager::IOManager()
{
}
