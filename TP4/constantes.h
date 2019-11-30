#ifndef CONSTANTES_H_INCLUDED
#define CONSTANTES_H_INCLUDED

#include <string>

#define SCREEN_WIDTH        1000
#define SCREEN_HEIGHT       600
#define LAST_DOSIS_SPRITE   20
#define FILE_EXTENSION      ".png";
#define COMMON_RED          (Uint8) 255
#define COMMON_GREEN        (Uint8) 255
#define COMMON_BLUE         (Uint8) 255
#define SECONDARY_RED       255
#define SECONDARY_GREEN     200
#define SECONDARY_BLUE      000
#define CELULA_SIZE         60
#define ANTICUERPO_WIDTH    28
#define ANTICUERPO_HEIGHT   30
#define NANOBOT_WIDTH       73
#define NANOBOT_HEIGHT      37
#define DOSIS_WIDTH         178
#define DOSIS_HEIGHT        152
#define VALOR_GRANDE 999999
#define FONDO_PATH          "images/fondo.png"
#define CELULA_S_PATH       "images/celulaSana.png"
#define CELULA_X_PATH       "images/celulaX.png"
#define CELULA_Y_PATH       "images/celulaY.png"
#define CELULA_Z_PATH       "images/celulaZ.png"
#define ANTICUERPO_PATH     "images/anticuerpo.png"
#define NANOBOT_PATH        "images/nanobot.png"
#define DOSIS_PATH          "images/dosis/alpha-"

const std::string PATHS[7] = {FONDO_PATH,NANOBOT_PATH,CELULA_S_PATH,CELULA_X_PATH,CELULA_Y_PATH,CELULA_Z_PATH,ANTICUERPO_PATH};
const int SCREEN_FPS = 30;
const int INTERVALO_MUTACION = 30;

const std::string ARCHIVO_DATOS = "estado.txt";
const int MAX_ELEMENTOS = 100;
const int ACCION_MOSTRAR_TODOS = 1;
const int ACCION_MOSTRAR_UN_ELEMENTO = 2;
const int ACCION_SALIR = 3;
const char CARACTER_SEPARADOR = ' ';
const std::string TIPO_ELEMENTO_ANTICUERPO = "anticuerpo";
const std::string TIPO_ELEMENTO_CELULA = "celula";
const std::string TIPO_CELULA_DESCONOCIDO = "desconocido";
const std::string TIPO_CELULA_S = "S";
const std::string TIPO_CELULA_X = "X";
const std::string TIPO_CELULA_Y = "Y";
const std::string TIPO_CELULA_Z = "Z";
const std::string TIPO_ELEMENTO_DOSIS = "dosis";
const std::string TIPO_DOSIS_A = "A";
const std::string TIPO_DOSIS_B = "B";
const std::string TIPO_DOSIS_DESCONOCIDA = "desconocido";
const int TAMANIO_CELULA = 60;
const int CORRIMIENTO = 100;

#endif // CONSTANTES_H_INCLUDED
