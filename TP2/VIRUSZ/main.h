#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include "tejido.h"

/*
 * Muestra la pantalla de bienvenida a la aplicacion.
 */
void mostrar_bienvenida();

/*
 * Muestra el menu principal de la aplicacion.
 */
void menu_principal(Tejido* tejido);

/*
 * Solicita el ingreso de un numero por teclado, dentro del rango
 * comprendido entre min_valor y max_valor.
 */
unsigned int solicitar_valor(unsigned int min_valor, unsigned int max_valor);

#endif // MAIN_H_INCLUDED
