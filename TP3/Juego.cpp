#include "Juego.h"

using namespace std;

bool Juego::iniciar(const char *title, int xpos, int ypos, int flags) {
    entorno.iniciar(title, xpos, ypos, flags);
    return true;
}

Juego::Juego() {
    running = false;
}

void Juego::correr()
{
    running = true;
    FPSManager fpsManager(SCREEN_FPS);

    while(running) {
        fpsManager.start();

        manejarEventos();
        renderizar();

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
