#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include "tejido.h"

/*
 * Muestra la pantalla de bienvenida a la aplicacion.
 */
void mostrarBienvenida();

/*
 * Muestra el menu principal de la aplicacion.
 */
void menu_principal(Tejido* tejido);

#endif // MAIN_H_INCLUDED
