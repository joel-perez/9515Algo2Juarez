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

imagenes obtener_tipo_imagenes_desde_string(std::string tipo_elemento) {
    if (tipo_elemento == TIPO_CELULA_S)
        return CELULA_S;
    else if (tipo_elemento == TIPO_CELULA_X)
        return CELULA_X;
    else if (tipo_elemento == TIPO_CELULA_Y)
        return CELULA_Y;
    else if (tipo_elemento == TIPO_CELULA_Z)
        return CELULA_Z;
    else
        return CELULA_S; // TODO: Ver bien que valor iria por default, igualmente a este caso no va a llegar.
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
