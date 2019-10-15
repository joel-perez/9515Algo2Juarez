#include "texto.h"

using namespace std;

string int_to_string(int number){
    std::ostringstream convert;
    convert << number;
    return convert.str();
}

string float_to_string(float number){
    std::ostringstream ss;
    ss << number;
    std::string s(ss.str());
}

string rellenar_derecha(string str, unsigned int cant, char pad) {
    if (str.length() < cant)
        str += string(cant - str.length(), pad);
    return str;
}
