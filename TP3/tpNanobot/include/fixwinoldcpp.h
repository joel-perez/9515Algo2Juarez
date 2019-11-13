#ifndef FIXWINOLDCPP_H_INCLUDED
#define FIXWINOLDCPP_H_INCLUDED

#ifdef _WIN32

#define SDL_MAIN_HANDLED

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

#ifndef nullptr
#define nullptr 0
#endif

#include <cstddef>

#ifndef to_string
std::string to_string(int number);
#endif

#endif

#endif // FIXWINOLDCPP_H_INCLUDED



//#define puts _puts
//#include <stdio.h>
//#undef puts