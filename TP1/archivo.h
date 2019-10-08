#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED

#include <iostream>
#include <string>
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "archivo.h"
#include "constantes.h"
#include "texto.h"
#include "conversiones.h"
#include "ResumenElementos.h"
#include "tipocelula.h"

/*
 * Realiza la lectura de los elementos desde un archivo y devuelve
 * un resumen de las cantidades y porcentajes de celulas, anticuerpos
 * y dosis.
 */
ResumenElementos* cargarResumen();

#endif // ARCHIVO_H_INCLUDED
