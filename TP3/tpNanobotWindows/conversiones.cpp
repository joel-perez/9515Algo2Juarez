#include "conversiones.h"

using namespace std;

string to_string(int number) {
    ostringstream oss;
    oss << number;
    return oss.str();
}
