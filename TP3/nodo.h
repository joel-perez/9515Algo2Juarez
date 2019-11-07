#ifndef NODO_H_
#define NODO_H_

template <class T> class Nodo {
  private:
    T dato;
    Nodo<T>* siguiente;
  public:
    // post: el Nodo resulta inicializado con el dato dado y sin un Nodo siguiente.
    Nodo(T dato) {
      this->dato = dato;
      this->siguiente = NULL;
    }
    //post: devuelve el valor del dato.
    T obtener_dato() {
      return this->dato;
    }
    //post: cambia el valor del dato.
    void cambiar_dato(T nuevoDato) {
      this->dato = nuevoDato;
    }
    //post: devuelve el siguiente Nodo.
    Nodo<T>* obtener_siguiente() {
      return this->siguiente;
    }
    //post: cambia el siguiente Nodo por nuevo_siguiente.
    void cambiar_siguiente(Nodo<T>* nuevo_siguiente) {
      this->siguiente = nuevo_siguiente;
    }
};

#endif
