#include "Juego.h"

//https://stackoverflow.com/a/997988   // TODO: Eliminar esto cuando terminemos las pruebas...
#include <ctime>                       // TODO: Eliminar esto cuando terminemos las pruebas...
#include <iostream>                    // TODO: Eliminar esto cuando terminemos las pruebas...

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

void loguear_evento(string descripcion_evento) { // TODO: Eliminar esto cuando terminemos las pruebas...
    //https://stackoverflow.com/a/997988         // TODO: Eliminar esto cuando terminemos las pruebas...
    std::time_t t = std::time(0);                // TODO: Eliminar esto cuando terminemos las pruebas...
    std::tm* now = std::localtime(&t);           // TODO: Eliminar esto cuando terminemos las pruebas...
    std::cout << (now->tm_year + 1900) << '-'    // TODO: Eliminar esto cuando terminemos las pruebas...
         << (now->tm_mon + 1) << '-'             // TODO: Eliminar esto cuando terminemos las pruebas...
         <<  now->tm_mday << ' '                 // TODO: Eliminar esto cuando terminemos las pruebas...
         <<  now->tm_hour << ':'                 // TODO: Eliminar esto cuando terminemos las pruebas...
         <<  now->tm_min << ':'                  // TODO: Eliminar esto cuando terminemos las pruebas...
         <<  now->tm_sec << " - "                // TODO: Eliminar esto cuando terminemos las pruebas...
         << descripcion_evento << endl;          // TODO: Eliminar esto cuando terminemos las pruebas...
}                                                // TODO: Eliminar esto cuando terminemos las pruebas...

// Se encarga de manejar los eventos de teclado a traves de la clase "InputManager"
// En general, para saber si una tecla esta siendo presionada se utilizara
// el metodo "isKeyDown(KEY)". Para saber que KEY pasar por parametro, consultar
// el archivo "InputTable.h" que mapea codigos de teclado de SDL.
void Juego::manejarEventos() {
    // loguear_evento("void Juego::manejarEventos()"); // TODO: Eliminar esto cuando terminemos las pruebas...

    InputManager* inputManager = InputManager::getInstance();
    inputManager->update();
    if(inputManager->quitRequested())
        running = false;

    if(inputManager->isKeyDown(KEY_A) || entorno.dosisAExplotando()) {
        entorno.explotarDosis(DosisA);
        loguear_evento("entorno.explotarDosis(A);"); // TODO: Eliminar esto cuando terminemos las pruebas...
    }

    if(inputManager->isKeyDown(KEY_B) || entorno.dosisBExplotando()) {
        entorno.explotarDosis(DosisB);
        loguear_evento("entorno.explotarDosis(B);"); // TODO: Eliminar esto cuando terminemos las pruebas...
    }

    //Your code here
    if(inputManager->isKeyDown(KEY_ESCAPE)) {
        SDL_Quit();
        exit(0);
    }
    if(inputManager->isKeyDown(KEY_UP) && !inputManager->isKeyDown(KEY_LEFT) && !inputManager->isKeyDown(KEY_RIGHT) && entorno.nanobot_pos_y >= 0) {
        entorno.nanobot_pos_y -= 10;
        loguear_evento("nanobot arriba.");            // TODO: Eliminar esto cuando terminemos las pruebas...
    }
    if(inputManager->isKeyDown(KEY_DOWN) && !inputManager->isKeyDown(KEY_LEFT) && !inputManager->isKeyDown(KEY_RIGHT) && entorno.nanobot_pos_y <= SCREEN_HEIGHT - NANOBOT_HEIGHT) {
        entorno.nanobot_pos_y += 10;
        loguear_evento("nanobot abajo.");             // TODO: Eliminar esto cuando terminemos las pruebas...
    }
    if(inputManager->isKeyDown(KEY_LEFT) && !inputManager->isKeyDown(KEY_UP) && !inputManager->isKeyDown(KEY_DOWN) && entorno.nanobot_pos_x >= 0) {
        entorno.nanobot_pos_x -= 10;
        loguear_evento("nanobot izquierda.");         // TODO: Eliminar esto cuando terminemos las pruebas...
    }
    if(inputManager->isKeyDown(KEY_RIGHT) && !inputManager->isKeyDown(KEY_UP) && !inputManager->isKeyDown(KEY_DOWN) && entorno.nanobot_pos_x <= SCREEN_WIDTH - NANOBOT_WIDTH) {
        entorno.nanobot_pos_x += 10;
        loguear_evento("nanobot derecha.");           // TODO: Eliminar esto cuando terminemos las pruebas...
    }

}

Juego::~Juego(){
}
