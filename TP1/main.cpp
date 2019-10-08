#include "main.h"

using namespace std;

/*
 * Trabajo Practico Individual Nro 1.
 * Metodo principal de la aplicacion.
 */
int main()
{
    mostrarBienvenida();
    ResumenElementos* resumenElementos = cargarResumen();
    mostrarResultados(resumenElementos);
    solicitarEnterParaSalir();
    delete resumenElementos;
    return 0;
}
