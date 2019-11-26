#include "Juego.h"

using namespace std;

bool Juego::iniciar(const char *title, int xpos, int ypos, int flags) {
    entorno.iniciar(title, xpos, ypos, flags);
    return true;
}

Juego::Juego() {
    running = false;
}

resultado_juego Juego::obtener_resultado_juego(){
    unsigned int total_celulas = entorno.obtener_cantidad_total_celulas();
    unsigned int cant_celulas_s = entorno.obtener_cantidad_celulas(TIPO_CELULA_S);
    unsigned int cant_celulas_z = entorno.obtener_cantidad_celulas(TIPO_CELULA_Z);
    if (100 * cant_celulas_s / (float) total_celulas == 100)
        return GANASTE;
    else if (100 * cant_celulas_z / (float) total_celulas > 50)
        return PERDISTE;
    return JUGANDO;
}

void Juego::correr()
{
    running = true;
    FPSManager fpsManager(SCREEN_FPS);
    Uint32 milisegundos_inicial = fpsManager.obtener_milisegundos_actuales();

    while(running) {
        fpsManager.start();

        manejarEventos();
        renderizar();

        if (fpsManager.obtener_milisegundos_actuales() >= milisegundos_inicial + INTERVALO_MUTACION * 1000) {
            milisegundos_inicial = fpsManager.obtener_milisegundos_actuales();
            entorno.mutar_celulas();
        }

        fpsManager.stop();
    }
}

void Juego::renderizar() {
    entorno.renderizarTodo();
}

void Juego::limpiar() {
    entorno.limpiar();
}

// Se encarga de manejar los eventos de teclado a traves de la clase "InputManager"
// En general, para saber si una tecla esta siendo presionada se utilizara
// el metodo "isKeyDown(KEY)". Para saber que KEY pasar por parametro, consultar
// el archivo "InputTable.h" que mapea codigos de teclado de SDL.
void Juego::manejarEventos() {
    InputManager* inputManager = InputManager::getInstance();
    inputManager->update();
    if(inputManager->quitRequested())
        running = false;

    if(inputManager->isKeyDown(KEY_A) || entorno.dosisAExplotando()) {
        entorno.explotarDosis(DosisA);
    }

    if(inputManager->isKeyDown(KEY_B) || entorno.dosisBExplotando()) {
        entorno.explotarDosis(DosisB);
    }

    //Your code here
    if(inputManager->isKeyDown(KEY_ESCAPE)) {
        running = false;
    }
    if(inputManager->isKeyDown(KEY_UP) && !inputManager->isKeyDown(KEY_LEFT) && !inputManager->isKeyDown(KEY_RIGHT) && entorno.obtener_nanobot_pos_y() >= 0) {
        entorno.cambiar_nanobot_pos_y(entorno.obtener_nanobot_pos_y() - 10);
    }
    if(inputManager->isKeyDown(KEY_DOWN) && !inputManager->isKeyDown(KEY_LEFT) && !inputManager->isKeyDown(KEY_RIGHT) && entorno.obtener_nanobot_pos_y() <= SCREEN_HEIGHT - NANOBOT_HEIGHT) {
        entorno.cambiar_nanobot_pos_y(entorno.obtener_nanobot_pos_y() + 10);
    }
    if(inputManager->isKeyDown(KEY_LEFT) && !inputManager->isKeyDown(KEY_UP) && !inputManager->isKeyDown(KEY_DOWN) && entorno.obtener_nanobot_pos_x() >= 0) {
        entorno.cambiar_nanobot_pos_x(entorno.obtener_nanobot_pos_x() - 10);
    }
    if(inputManager->isKeyDown(KEY_RIGHT) && !inputManager->isKeyDown(KEY_UP) && !inputManager->isKeyDown(KEY_DOWN) && entorno.obtener_nanobot_pos_x() <= SCREEN_WIDTH - NANOBOT_WIDTH) {
        entorno.cambiar_nanobot_pos_x(entorno.obtener_nanobot_pos_x() + 10);
    }
}

Juego::~Juego(){
}
