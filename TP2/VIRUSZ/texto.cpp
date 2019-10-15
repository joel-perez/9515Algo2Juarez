#include "texto.h"

using namespace std;

string int_to_string(int number){
    std::ostringstream convert;
    convert << number;
    return convert.str();
}

string rellenar_derecha(string str, unsigned int cant, char pad) {
    if (str.length() < cant)
        str += string(cant - str.length(), pad);
    return str;
}
