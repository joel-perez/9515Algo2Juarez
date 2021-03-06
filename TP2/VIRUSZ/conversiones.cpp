#include "conversiones.h"

using namespace std;

TipoDosis obtener_tipo_dosis_desde_string(string tipo_dosis)
{
    if (tipo_dosis == TIPO_DOSIS_A)
        return A;
    else if (tipo_dosis == TIPO_DOSIS_B)
        return B;
    else
        return DosisDesconocida;
}

string obtener_string_desde_tipo_dosis(TipoDosis tipo_dosis)
{
    switch(tipo_dosis)
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
