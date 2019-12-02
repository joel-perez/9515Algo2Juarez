#ifndef CONSTANTES_H_INCLUDED
#define CONSTANTES_H_INCLUDED

#include <string>

#define ANTICUERPO_HEIGHT   30
#define ANTICUERPO_PATH     "images/anticuerpo.png"
#define ANTICUERPO_WIDTH    28
#define CELULA_SIZE         60
#define CELULA_S_PATH       "images/celulaSana.png"
#define CELULA_X_PATH       "images/celulaX.png"
#define CELULA_Y_PATH       "images/celulaY.png"
#define CELULA_Z_PATH       "images/celulaZ.png"
#define COMMON_BLUE         (Uint8) 255
#define COMMON_GREEN        (Uint8) 255
#define COMMON_RED          (Uint8) 255
#define DOSIS_HEIGHT        152
#define DOSIS_PATH          "images/dosis/alpha-"
#define DOSIS_WIDTH         178
#define FILE_EXTENSION      ".png";
#define FONDO_PATH          "images/fondo.png"
#define LAST_DOSIS_SPRITE   20
#define NANOBOT_HEIGHT      37
#define NANOBOT_PATH        "images/nanobot.png"
#define NANOBOT_WIDTH       73
#define SCREEN_HEIGHT       600
#define SCREEN_WIDTH        1000
#define SECONDARY_BLUE      000
#define SECONDARY_GREEN     200
#define SECONDARY_RED       255

const int TOTAL_FRAMES_INYECCION = 30;
const int TOTAL_FRAMES_ATRAPADA = 15;
const char CARACTER_SEPARADOR = ' ';
const int ACCION_MOSTRAR_TODOS = 1;
const int ACCION_MOSTRAR_UN_ELEMENTO = 2;
const int ACCION_SALIR = 3;
const int CORRIMIENTO = 100;
const int INTERVALO_MUTACION = 30;
const int MAX_ELEMENTOS = 100;
const int SCREEN_FPS = 30;
const int TAMANIO_CELULA = 60;
const std::string ARCHIVO_DATOS = "estado.txt";
const std::string PATHS[7] = {FONDO_PATH,NANOBOT_PATH,CELULA_S_PATH,CELULA_X_PATH,CELULA_Y_PATH,CELULA_Z_PATH,ANTICUERPO_PATH};
const std::string TIPO_CELULA_DESCONOCIDO = "desconocido";
const std::string TIPO_CELULA_S = "S";
const std::string TIPO_CELULA_X = "X";
const std::string TIPO_CELULA_Y = "Y";
const std::string TIPO_CELULA_Z = "Z";
const std::string TIPO_DOSIS_A = "A";
const std::string TIPO_DOSIS_B = "B";
const std::string TIPO_DOSIS_DESCONOCIDA = "desconocido";
const std::string TIPO_ELEMENTO_ANTICUERPO = "anticuerpo";
const std::string TIPO_ELEMENTO_CELULA = "celula";
const std::string TIPO_ELEMENTO_DOSIS = "dosis";

#endif // CONSTANTES_H_INCLUDED
