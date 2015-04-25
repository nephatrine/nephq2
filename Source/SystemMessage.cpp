#include "SystemMessage.h"
#include <SDL_messagebox.h>
#include <iostream>

void System::Message::Information( const std::string &message )
{	SDL_ShowSimpleMessageBox( SDL_MESSAGEBOX_INFORMATION, "Information", message.c_str(), nullptr );
	std::cout << "[INFO] " << message;
}

void System::Message::Warning( const std::string &message )
{	SDL_ShowSimpleMessageBox( SDL_MESSAGEBOX_WARNING, "Warning", message.c_str(), nullptr );
	std::cout << "[WARN] " << message;
}

void System::Message::Error( const std::string &message )
{	SDL_ShowSimpleMessageBox( SDL_MESSAGEBOX_ERROR, "Error", message.c_str(), nullptr );
	std::cerr << "[ERR] " << message;
}

void System::Message::Fatal( const std::string &message )
{	SDL_ShowSimpleMessageBox( SDL_MESSAGEBOX_ERROR, "Fatal Error", message.c_str(), nullptr );
	std::cerr << "[FATAL] " << message;
}
