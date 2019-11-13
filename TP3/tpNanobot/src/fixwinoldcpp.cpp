#include "fixwinoldcpp.h"

#ifdef _WIN32
#ifndef to_string

using namespace std;

string to_string(int number) {
    std::ostringstream oss;
    oss << number;
    return oss.str();
}

#endif

#endif