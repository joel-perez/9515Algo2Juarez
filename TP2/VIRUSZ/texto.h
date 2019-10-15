#ifndef TEXTO_H_INCLUDED
#define TEXTO_H_INCLUDED

#include <iostream>
#include <string>
#include <sstream>

/*
 * Convierte un valor entero a un string.
 */
std::string int_to_string(int number);

/*
 * Convierte un valor float a un string.
 */
std::string float_to_string(float number);

/*
 * Devuelve un string mostrando el texto original, y ademas le agrega un
 * relleno de cant caracteres cuyo valor es pad.
 */
std::string rellenar_derecha(std::string str, unsigned int cant, char pad);

#endif // TEXTO_H_INCLUDED
