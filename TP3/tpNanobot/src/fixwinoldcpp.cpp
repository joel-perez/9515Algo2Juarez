#include "fixwinoldcpp.h"

#ifdef _WIN32

using namespace std;

string to_string(int number) {
    std::ostringstream oss;
    oss << number;
    return oss.str();
}

#endif