#include "conversiones.h"

using namespace std;

TipoCelula ObtenerTipoCelulaDesdeString(string tipoCelula)
{
    if (tipoCelula == TIPO_CELULA_S)
        return S;
    else if (tipoCelula == TIPO_CELULA_X)
        return X;
    else if (tipoCelula == TIPO_CELULA_Y)
        return Y;
    else if (tipoCelula == TIPO_CELULA_Z)
        return Z;
    else
        return CelulaDesconocida;
}

string ObtenerStringDesdeTipoCelula(TipoCelula tipoCelula)
{
    switch(tipoCelula)
    {
    case S:
        return TIPO_CELULA_S;
        break;
    case X:
        return TIPO_CELULA_X;
        break;
    case Y:
        return TIPO_CELULA_Y;
        break;
    case Z:
        return TIPO_CELULA_Z;
        break;
    default:
        return TIPO_CELULA_DESCONOCIDA;
        break;
    }
}

TipoDosis ObtenerTipoDosisDesdeString(string tipoDosis)
{
    if (tipoDosis == TIPO_DOSIS_A)
        return A;
    else if (tipoDosis == TIPO_DOSIS_B)
        return B;
    else
        return DosisDesconocida;
}

string ObtenerStringDesdeTipoDosis(TipoDosis tipoDosis)
{
    switch(tipoDosis)
    {
    case A:
        return TIPO_DOSIS_A;
        break;
    case B:
        return TIPO_DOSIS_B;
        break;
    default:
        return TIPO_DOSIS_DESCONOCIDA;
        break;
    }
}
