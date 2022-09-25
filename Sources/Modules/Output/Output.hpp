#ifndef MODULES_OUTPUT_H
#define MODULES_OUTPUT_H

#include <string>

namespace ogl {
	namespace output {
		class Output
		{
		public:
			Output();
			~Output();

			template<typename T, typename R>
			static void write(T, R);

			template<typename T>
			static void write(T);

			template<>
			static void write(std::string input);

			template<>
			static void write(std::string input, std::string file_path);
		};
	}
}
#endif
