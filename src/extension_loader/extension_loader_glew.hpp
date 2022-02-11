#ifndef EXTENSION_LOADER_GLEW_H
#define EXTENSION_LOADER_GLEW_H

#include "extension_loader.hpp"

class ExtensionLoaderGLEW : public IExtensionLoader
{
public:
	virtual void init() override;
};
#endif // EXTENSION_LOADER_GLEW_H
