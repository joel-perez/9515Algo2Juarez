#include "ResumenElementos.h"

using namespace std;

ResumenElementos::ResumenElementos()
{
    int i;
    for (i = 0; i <= 4; i++)
        cantidadCelulas[i] = 0;

    for (i = 0; i <= 2; i++)
        cantidadDosis[i] = 0;

    cantidadAnticuerpos = 0;
}

ResumenElementos::~ResumenElementos()
{
}

void ResumenElementos::AgregarCelula(TipoCelula tipoCelula)
{
    cantidadCelulas[tipoCelula]++;
}

int ResumenElementos::ObtenerCantidadCelulas(TipoCelula tipoCelula)
{
    return cantidadCelulas[tipoCelula];
}

int ResumenElementos::ObtenerPorcentajeCelulas(TipoCelula tipoCelula)
{
    return cantidadCelulas[tipoCelula] * 100 / ObtenerTotalCelulas();
}

int ResumenElementos::ObtenerTotalCelulas()
{
    int resultado = 0;
    for (int i = 0; i <= 4; i++)
        resultado += cantidadCelulas[i];
    return resultado;
}

void ResumenElementos::AgregarAnticuerpo()
{
    cantidadAnticuerpos++;
}

int ResumenElementos::ObtenerCantidadAnticuerpos()
{
    return cantidadAnticuerpos;
}

void ResumenElementos::AgregarDosis(TipoDosis tipoDosis, int cantidadDosisActual)
{
    cantidadDosis[tipoDosis] += cantidadDosisActual;
}

int ResumenElementos::ObtenerCantidadDosis(TipoDosis tipoDosis)
{
    return cantidadDosis[tipoDosis];
}

int ResumenElementos::ObtenerPorcentajeDosis(TipoDosis tipoDosis)
{
    return cantidadDosis[tipoDosis] * 100 / ObtenerTotalDosis();
}

int ResumenElementos::ObtenerTotalDosis()
{
    int resultado = 0;
    for (int i = 0; i <= 2; i++)
        resultado += cantidadDosis[i];
    return resultado;
}
