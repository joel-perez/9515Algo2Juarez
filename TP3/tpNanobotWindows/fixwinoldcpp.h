#ifndef FIXWINOLDCPP_H_INCLUDED
#define FIXWINOLDCPP_H_INCLUDED

#define SDL_MAIN_HANDLED

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

#ifndef nullptr
#define nullptr 0
#endif

#include <cstddef>

std::string to_string(int number);

#endif // FIXWINOLDCPP_H_INCLUDED
