#ifndef CONVERSIONES_H_INCLUDED
#define CONVERSIONES_H_INCLUDED

#include <string>
#include "constantes.h"
#include "tipodosis.h"

/*
 * Devuelve un valor enumerado a partir del string recibido como parametro.
 */
TipoDosis obtener_tipo_dosis_desde_string(std::string tipo_dosis);

/*
 * Devuelve un string con la descripcion de la dosis en base al
 * valor enumerado recibido como parametro.
 */
std::string obtener_string_desde_tipo_dosis(TipoDosis tipo_dosis);


#endif // CONVERSIONES_H_INCLUDED
