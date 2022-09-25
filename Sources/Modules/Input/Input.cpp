#include "Input.hpp"

using namespace ogl::input;

Input::Input() {}

Input::~Input() {}

void Input::read(void) {}

template<>
std::vector<char>& Input::read(std::string file_path)
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

std::streamoff Input::file_size(std::ifstream& file)
{
	file.seekg(0, std::ios::end);
	std::streamoff file_size = file.tellg();

	file.seekg(0, std::ios::beg);
	file_size -= file.tellg();

	return file_size;
}

template<typename T, typename R>
T& Input::read(R)
{
	// TODO: insert return statement here
}
