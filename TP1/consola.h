#ifndef CONSOLA_H_INCLUDED
#define CONSOLA_H_INCLUDED

#include <iostream>
#include "consola.h"
#include "constantes.h"
#include "texto.h"
#include "conversiones.h"
#include "ResumenElementos.h"

/*
 * Muestra la pantalla de bienvenida a la aplicacion.
 */
void mostrarBienvenida();

/*
 * Muestra por pantalla una tabla con las cantidades y
 * porcentajes de cada celula, anticuerpo y dosis.
 */
void mostrarResultados(ResumenElementos* resumenElementos);

/*
 * Muestra por pantalla una fila generica de la tabla de cantidades y porcentajes.
 */
void mostrarFila(std::string columna1, std::string columna2, std::string columna3);

/*
 * Muestra por pantalla una fila con datos de la celula del tipo indicado.
 */
void mostrarFilaCelulas(TipoCelula tipoCelula, ResumenElementos* resumenElementos);

/*
 * Muestra por pantalla una fila con datos de la dosis del tipo indicado.
 */
void mostrarFilaDosis(TipoDosis tipoDosis, ResumenElementos* resumenElementos);

/*
 * Solicita presionar la tecla enter para salir.
 */
void solicitarEnterParaSalir();

#endif // CONSOLA_H_INCLUDED
