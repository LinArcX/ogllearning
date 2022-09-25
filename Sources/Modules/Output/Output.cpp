#include "Output.hpp"

using namespace ogl::output;

Output::Output() {}

Output::~Output() {}

template<>
void Output::write(std::string Output) {}

template<>
void Output::write(std::string Output, std::string file_path) {}

template<typename T, typename R>
void Output::write(T, R) {}

template<typename T>
void Output::write(T) {}
