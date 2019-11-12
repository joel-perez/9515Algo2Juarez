//
// Created by caropistillo
//

#include "Juego.h"

using namespace std;

const int SCREEN_FPS = 30;


bool Juego::iniciar(const char *title, int xpos, int ypos, int flags) {

    entorno.iniciar(title,xpos,ypos,flags);

    return false; //TODO: Ver que hay que devolver...
}


Juego::Juego(){

	running = false;
}

void Juego::correr() {
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
    if(inputManager->quitRequested()) running = false;

    if(inputManager->isKeyDown(KEY_A)||entorno.dosisAExplotando())
    {
        entorno.explotarDosis(A);
    }

    if(inputManager->isKeyDown(KEY_B)||entorno.dosisBExplotando())
    {
        entorno.explotarDosis(B);
    }

    //Your code here

}

