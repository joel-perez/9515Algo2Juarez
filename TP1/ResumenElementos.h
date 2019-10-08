#ifndef RESUMENELEMENTOS_H
#define RESUMENELEMENTOS_H

#include <iostream>
#include <string>
#include "tipocelula.h"
#include "tipodosis.h"

class ResumenElementos
{
public:
    /*
     * POST: Inicializa la cantidad de celulas, anticuerpos y dosis para el resumen actual.
     */
    ResumenElementos();

    /*
     * POST: Libera los recursos utilizados, en caso de ser necesario.
     */
    virtual ~ResumenElementos();

    /*
     * POST: Agrega una celula del tipo pasado como parametro.
     */
    void AgregarCelula(TipoCelula tipoCelula);

    /*
     * POST: Devuelve la cantidad actual de celulas del tipo indicado.
     */
    int ObtenerCantidadCelulas(TipoCelula tipoCelula);

    /*
     * POST: Devuelve el porcentaje de Celulas del tipo pasado
     *       como parametro, con respecto al total de celulas
     *       existentes al momento.
     */
    int ObtenerPorcentajeCelulas(TipoCelula tipoCelula);

    /*
     * POST: Devuelve la cantidad total de celulas cargadas al momento.
     */
    int ObtenerTotalCelulas();

    /*
     * POST: Agrega un anticuerpo.
     */
    void AgregarAnticuerpo();

    /*
     * POST: Obtiene la cantidad de anticuerpos al momento.
     */
    int ObtenerCantidadAnticuerpos();

    /*
     * POST: Agrega para el tipo de Dosis indicado, la cantidad pasada
     *       como parametro.
     */
    void AgregarDosis(TipoDosis tipoDosis, int cantidadDosisActual);

    /*
     * POST: Devuelve la cantidad de Dosis del tipo pasado como parametro.
     */
    int ObtenerCantidadDosis(TipoDosis tipoDosis);

    /*
     * POST: Devuelve el porcentaje de Dosis del tipo pasado como parametro,
     *       con respecto al total de dosis existentes al momento.
     */
    int ObtenerPorcentajeDosis(TipoDosis tipoDosis);

    /*
    * POST: Devuelve la cantidad total de dosis cargadas al momento.
    */
    int ObtenerTotalDosis();

private:
    int cantidadCelulas[5];
    int cantidadDosis[3];
    int cantidadAnticuerpos;
};

#endif // RESUMENELEMENTOS_H
