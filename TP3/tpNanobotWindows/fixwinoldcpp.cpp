#include "fixwinoldcpp.h"

using namespace std;

string to_string(int number) {
    std::ostringstream oss;
    oss << number;
    return oss.str();
}
