#include "texto.h"

using namespace std;

string intToString(int number)
{
    std::ostringstream convert;
    convert << number;
    return convert.str();
}

string rellenarDerecha(string str, unsigned int cant, char pad)
{
    if (str.length() < cant)
        str += string(cant - str.length(), pad);
    return str;
}
