#ifndef IO_MANAGER_H
#define IO_MANAGER_H
#include <mutex>
#include <atomic>
#include <vector>
#include <string>
#include <fstream>

class IOManager
{
public:
	~IOManager();
	static IOManager * instance();
	std::streamoff file_size(std::ifstream& file);
	bool read_file_to_buffer(std::string file_path, std::vector<char>& buffer);

private:
	IOManager();
	static std::recursive_mutex m_mutex;
	static std::atomic<IOManager*> m_io_manager;
};
#endif //IO_MANAGER_H
