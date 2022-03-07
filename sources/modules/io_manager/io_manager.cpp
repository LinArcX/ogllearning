#include "io_manager.hpp"

ogl::IOManager::IOManager() {}

ogl::IOManager::~IOManager() {}

void ogl::IOManager::read(void) {}

std::streamoff ogl::IOManager::file_size(std::ifstream& file)
{
	file.seekg(0, std::ios::end);
	std::streamoff file_size = file.tellg();

	file.seekg(0, std::ios::beg);
	file_size -= file.tellg();

	return file_size;
}

template<>
std::vector<char>& ogl::IOManager::read(std::string file_path)
{
	buffer.clear();

	std::ifstream file(file_path, std::ios::binary);
	if (file.fail())
	{
		perror(file_path.c_str());
		throw "exception";
		//return;
	}

	std::streamoff fsize = file_size(file);
	buffer.resize((size_t)fsize);
	file.read(&(buffer[0]), fsize);
	file.close();
}

template<>
void ogl::IOManager::write(std::string input) {}

template<>
void ogl::IOManager::write(std::string input, std::string file_path) {}

template<typename T, typename R>
T& ogl::IOManager::read(R)
{
	// TODO: insert return statement here
}

template<typename T, typename R>
void ogl::IOManager::write(T, R) {}

template<typename T>
void ogl::IOManager::write(T) {}
