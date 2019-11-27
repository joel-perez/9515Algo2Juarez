#ifndef NODO_H_
#define NODO_H_

template <class T> class Nodo {
  private:
    T dato;
    Nodo<T>* siguiente;
  public:
  
    // POST: El Nodo resulta inicializado con el dato dado y sin un Nodo siguiente.
    Nodo(T dato) {
      this->dato = dato;
      this->siguiente = NULL;
    }
	
    // POST: Devuelve el valor del dato.
    T obtener_dato() {
      return this->dato;
    }
	
    // POST: Cambia el valor del dato.
    void cambiar_dato(T nuevoDato) {
      this->dato = nuevoDato;
    }
	
    // POST: Devuelve un puntero al siguiente Nodo.
    Nodo<T>* obtener_siguiente() {
      return this->siguiente;
    }
	
    // POST: Cambia el siguiente Nodo por nuevo_siguiente.
    void cambiar_siguiente(Nodo<T>* nuevo_siguiente) {
      this->siguiente = nuevo_siguiente;
    }
};

#endif
