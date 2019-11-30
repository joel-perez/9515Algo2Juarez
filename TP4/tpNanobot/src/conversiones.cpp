#include "conversiones.h"

using namespace std;

string int_to_string(int number) {
    std::ostringstream oss;
    oss << number;
    return oss.str();
}
