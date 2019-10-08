#include "consola.h"

using namespace std;

void mostrarBienvenida()
{
    cout << "Algoritmos y Programacion II" << endl
         << "Trabajo Practico Individual Nro 1: Celulas, Anticuerpos y Suero" << endl
         << "Oscar Joel Perez - Legajo 99072" << endl
         << endl;
}

void mostrarResultados(ResumenElementos* resumenElementos)
{
    mostrarFila(RESULTADOS_ENCABEZADO_ELEMENTO, RESULTADOS_ENCABEZADO_CANTIDAD, RESULTADOS_ENCABEZADO_PORCENTAJE);
    mostrarFilaCelulas(S, resumenElementos);
    mostrarFilaCelulas(X, resumenElementos);
    mostrarFilaCelulas(Y, resumenElementos);
    mostrarFilaCelulas(Z, resumenElementos);
    mostrarFila(RESULTADOS_ELEMENTO_ANTICUERPOS, intToString(resumenElementos->ObtenerCantidadAnticuerpos()), ESPACIO);
    mostrarFilaDosis(A, resumenElementos);
    mostrarFilaDosis(B, resumenElementos);
    cout << endl;
}

void mostrarFila(string columna1, string columna2, string columna3)
{
    cout << rellenarDerecha(columna1, ANCHO_COLUMNAS_TABLA_RESUMEN, CARACTER_RELLENO_DERECHA)
         << rellenarDerecha(columna2, ANCHO_COLUMNAS_TABLA_RESUMEN, CARACTER_RELLENO_DERECHA)
         << rellenarDerecha(columna3, ANCHO_COLUMNAS_TABLA_RESUMEN, CARACTER_RELLENO_DERECHA)
         << endl;
}

void mostrarFilaCelulas(TipoCelula tipoCelula, ResumenElementos* resumenElementos)
{
    mostrarFila(RESULTADOS_ELEMENTO_CELULAS + ESPACIO + ObtenerStringDesdeTipoCelula(tipoCelula),
                intToString(resumenElementos->ObtenerCantidadCelulas(tipoCelula)),
                intToString(resumenElementos->ObtenerPorcentajeCelulas(tipoCelula)));
}

void mostrarFilaDosis(TipoDosis tipoDosis, ResumenElementos* resumenElementos)
{
    mostrarFila(RESULTADOS_ELEMENTO_DOSIS + ESPACIO + ObtenerStringDesdeTipoDosis(tipoDosis),
                intToString(resumenElementos->ObtenerCantidadDosis(tipoDosis)),
                intToString(resumenElementos->ObtenerPorcentajeDosis(tipoDosis)));
}

void solicitarEnterParaSalir()
{
    cout << "Presione ENTER para Salir." << endl;
    cin.get();
}
