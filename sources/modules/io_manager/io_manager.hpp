#ifndef IO_MANAGER_H
#define IO_MANAGER_H

#include <vector>
#include <string>
#include <fstream>

namespace ogl {
	class IOManager
	{
	public:
		IOManager();
		~IOManager();

		static void read(void);

		template<typename T>
		static T& read(void);

		template<typename T, typename R>
		static T& read(R);

		template<typename T, typename R>
		static void write(T, R);

		template<typename T>
		static void write(T);

		template<>
		static std::vector<char>& read(void);

		template<>
		static std::vector<char>& read(std::string file_path);

		template<>
		static void write(std::string input);

		template<>
		static void write(std::string input, std::string file_path);

	private:
		inline static std::vector<char> buffer;
		static std::streamoff file_size(std::ifstream& file);
	};
}
#endif
