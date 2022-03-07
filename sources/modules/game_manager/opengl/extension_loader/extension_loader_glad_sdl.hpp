#ifndef EXTENSION_LOADER_GLAD_SDL_H
#define EXTENSION_LOADER_GLAD_SDL_H

#include "extension_loader.hpp"

class ExtensionLoaderGladSdl
	: public IExtensionLoader
{
public:
	virtual void init() override;
};
#endif

