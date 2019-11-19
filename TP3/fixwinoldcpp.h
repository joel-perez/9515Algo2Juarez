#ifndef FIXWINOLDCPP_H_INCLUDED
#define FIXWINOLDCPP_H_INCLUDED

#ifdef _WIN32

#define SDL_MAIN_HANDLED

#include <cstdlib>

#ifndef nullptr
#define nullptr 0
#endif

#endif

#endif // FIXWINOLDCPP_H_INCLUDED
