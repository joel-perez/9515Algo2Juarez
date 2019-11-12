#ifndef NODO_H
#define NODO_H

#ifndef NULL
#define NULL 0
#endif

#include <iostream>

class Nodo {
  private:
    int dato;
    Nodo* siguiente;
  public:
    // post: el Nodo resulta inicializado con el dato dado y sin un Nodo siguiente.
    Nodo(int dato) {
      this->dato = dato;
      this->siguiente = NULL;
    }
    //post: devuelve el valor del dato.
    int obtener_dato() {
      return this->dato;
    }
    //post: cambia el valor del dato.
    void cambiar_dato(int nuevoDato) {
      this->dato = nuevoDato;
    }
    //post: devuelve el siguiente Nodo.
    Nodo* obtener_siguiente() {
      return this->siguiente;
    }
    //post: cambia el siguiente Nodo por nuevo_siguiente.
    void cambiar_siguiente(Nodo* nuevo_siguiente) {
      this->siguiente = nuevo_siguiente;
    }
};

#endif
