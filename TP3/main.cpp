#include "main.h"

using namespace std;

Juego* juego = 0;

int main() {
    cout << "TP3 - Nanobot - Grupo: 'Sobrecargados'" << endl;
    juego = new Juego();
    juego->iniciar("TP3 - Nanobot - Grupo: 'Sobrecargados'", 100, 100, 0);
    juego->correr();
    juego->limpiar();
    delete juego;
    return 0;
}
