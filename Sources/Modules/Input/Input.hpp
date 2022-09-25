#ifndef MODULES_INPUT_H
#define MODULES_INPUT_H

#include <vector>
#include <string>
#include <fstream>

namespace ogl {
	namespace input {
		class Input
		{
		public:
			Input();
			~Input();

			static void read(void);

			template<typename T>
			static T& read(void);

			template<typename T, typename R>
			static T& read(R);

			template<>
			static std::vector<char>& read(void);

			template<>
			static std::vector<char>& read(std::string file_path);

		private:
			inline static std::vector<char> buffer;
			static std::streamoff file_size(std::ifstream& file);
		};
	}
}
#endif
