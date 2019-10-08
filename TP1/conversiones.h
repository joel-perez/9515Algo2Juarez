#ifndef CONVERSIONES_H_INCLUDED
#define CONVERSIONES_H_INCLUDED

#include <string>
#include "tipocelula.h"
#include "tipodosis.h"
#include "constantes.h"

/*
 * Devuelve un tipo de Celula S, X, Y, Z segun el string que reciba.
 */
TipoCelula ObtenerTipoCelulaDesdeString(std::string tipoCelula);

/*
 * Devuelve el string correspondiente al tipo de celula recibido.
 */
std::string ObtenerStringDesdeTipoCelula(TipoCelula tipoCelula);

/*
 * Devuelve un tipo de Dosis A, B segun el string que reciba.
 */
TipoDosis ObtenerTipoDosisDesdeString(std::string tipoDosis);

/*
 * Devuelve el string correspondiente al tipo de dosis recibido.
 */
std::string ObtenerStringDesdeTipoDosis(TipoDosis tipoDosis);

#endif // CONVERSIONES_H_INCLUDED
