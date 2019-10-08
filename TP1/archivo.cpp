#include "archivo.h"

using namespace std;

ResumenElementos* cargarResumen()
{
    ResumenElementos* resultado = new ResumenElementos();
    std::ifstream entrada;
    entrada.open(ARCHIVO_DATOS.c_str());

    std::string linea;
    if (entrada.fail())
    {
        throw string(ERROR_ABRIR_ARCHIVO_DATOS);
    }

    while (getline(entrada, linea))
    {
        std::stringstream ss(linea);
        std::string tipoElemento;
        std::string tipoCelula;
        std::string tipoDosis;
        int cantidadDosis;
        getline(ss, tipoElemento, CARACTER_SEPARADOR);

        if (tipoElemento == TIPO_ELEMENTO_CELULA)
        {
            ss >> tipoCelula;
            resultado->AgregarCelula(ObtenerTipoCelulaDesdeString(tipoCelula));
        }
        else if (tipoElemento == TIPO_ELEMENTO_ANTICUERPO)
        {
            resultado->AgregarAnticuerpo();
        }
        else if (tipoElemento == TIPO_ELEMENTO_DOSIS)
        {
            ss >> tipoDosis;
            ss >> cantidadDosis;
            resultado->AgregarDosis(ObtenerTipoDosisDesdeString(tipoDosis), cantidadDosis);
        }
    }
    entrada.close();
    return resultado;
}
