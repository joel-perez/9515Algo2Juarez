#include "texto.h"

using namespace std;

string int_to_string(int number) {
    ostringstream oss;
    oss << number;
    return oss.str();
}

string float_to_string(float number) {
    ostringstream oss;
    oss << number;
    return oss.str();
}

string rellenar_derecha(string str, unsigned int cant, char pad) {
    if (str.length() < cant)
        str += string(cant - str.length(), pad);
    return str;
}
