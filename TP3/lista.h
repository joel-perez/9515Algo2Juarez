#ifndef LISTA_H_
#define LISTA_H_

#include "Nodo.h"

template<class T> class Lista {
  private:
    Nodo<T>* primero;
    unsigned int tamanio;
    Nodo<T>* cursor;
  public:
    //post: Lista vacía.
    Lista();
    //post: Lista que tiene los mismos elementos que otra_lista. La instancia resulta en una copia de otra_lista.
    Lista(Lista<T>& otraLista);
    //post: indica si la Lista tiene algún elemento.
    bool esta_vacia();
    //post: devuelve la cantidad de elementos que tiene la Lista.
    unsigned int contar_elementos();
    //post: agrega el elemento al final de la Lista, en la posición:
    contar_elementos() + 1.
    void agregar(T elemento);
    //pre : posición pertenece al intervalo: [1, contar_elementos() + 1]
    //post: agrega el elemento en la posición indicada.
    void agregar(T elemento, unsigned int posicion);
    //post: agrega todos los elementos de otra_lista a partir de la posición contar_elementos() + 1.
    void agregar(Lista<T> &otra_lista);
    //pre : posición pertenece al intervalo: [1, contarElementos()]
    //post: devuelve el elemento en la posición indicada.
    T obtener(unsigned int posicion);
    //pre : posicioó pertenece al intervalo: [1, contarElementos()]
    //post: cambia el elemento en la posición indicada por el elemento dado.
    void asignar(T elemento, unsigned int posicion);
    //pre : posición pertenece al intervalo: [1, contarElementos()]
    //post: remueve de la Lista el elemento en la posición indicada.
    void remover(unsigned int posicion);
    //post: deja el cursor de la Lista preparado para hacer un nuevo recorrido sobre sus elementos.
    void iniciar_cursor();
    /* pre : se ha iniciado un recorrido (invocando el método iniciarCursor()) y desde entonces no se han agregado o removido elementos de la Lista.
      post: mueve el cursor y lo posiciona en el siguiente elemento del recorrido. El valor de retorno indica si el cursor quedó posicionado sobre un elemento
            o no (en caso de que la Lista esté vacía o no existan más elementos por recorrer.)
    */
    bool avanzar_cursor();
    /* pre : el cursor está posicionado sobre un elemento de la Lista, (fue invocado el método avanzarCursor() y devolvió true)
       post: devuelve el elemento en la posición del cursor.
        */
    T obtener_cursor();
    /* post: libera los recursos asociados a la Lista.*/
    ~Lista();
  private:
     /* pre : posición pertenece al intervalo: [1, contarElementos()]
        post: devuelve el nodo en la posición indicada. */
      Nodo<T>* obtener_nodo(unsigned int posicion); // NOTA: primitiva PRIVADA
};

template<class T> Lista<T>::Lista() {

   this->primero = NULL;
   this->tamanio = 0;
   this->cursor = NULL;
}

template<class T> Lista<T>::Lista(Lista<T>& otra_lista) {

   this->primero = NULL;
   this->tamanio = 0;
   this->cursor = NULL;

   /* copia los elementos de otraLista */
   this->agregar(otraLista);
}

template<class T> bool Lista<T>::esta_vacia() {

   return (this->tamanio == 0);
}

template<class T> unsigned int Lista<T>::contar_elementos() {

   return this->tamanio;
}

template<class T> void Lista<T>::agregar(T elemento) {

   this->agregar(elemento, this->tamanio + 1);
}

template<class T> void Lista<T>::agregar(T elemento, unsigned int posicion) {

   if ((posicion > 0) && (posicion <= this->tamanio + 1)) {

       Nodo<T>* nuevo = new Nodo<T>(elemento);

       if (posicion == 1) {

           nuevo->cambiar_siguiente(this->primero);
           this->primero = nuevo;

       } else {

           Nodo<T>* anterior = this->obtener_nodo(posicion - 1);
           nuevo->cambiar_siguiente(anterior->obtener_siguiente());
           anterior->cambiar_siguiente(nuevo);
       }

       this->tamanio++;

       /* cualquier recorrido actual queda invalidado */
       this->iniciar_cursor();
   }

}

template<class T> void Lista<T>::agregar(Lista<T> &otra_lista) {

   otra_lista.iniciar_cursor();
   while (otra_lista.avanzar_cursor()) {
       this->agregar(otra_lista.obtener_cursor());
   }
}

template<class T> T Lista<T>::obtener(unsigned int posicion) {

   T elemento;

   if ((posicion > 0) && (posicion <= this->tamanio)) {

       elemento = this->obtener_nodo(posicion)->obtener_dato();
   }

   return elemento;
}

template<class T> void Lista<T>::asignar(T elemento, unsigned int posicion) {

   if ((posicion > 0) && (posicion <= this->tamanio)) {

       this->obtener_nodo(posicion)->cambiar_dato(elemento);
   }
}

template<class T> void Lista<T>::remover(unsigned int posicion) {

   if ((posicion > 0) && (posicion <= this->tamanio)) {

       Nodo<T>* removido;

       if (posicion == 1) {

           removido = this->primero;
           this->primero = removido->obtener_siguiente();

       } else {

           Nodo<T>* anterior = this->obtener_nodo(posicion - 1);
           removido = anterior->obtener_siguiente();
           anterior->cambiar_siguiente(removido->obtener_siguiente());
       }

       delete removido;
       this->tamanio--;

       /* cualquier recorrido actual queda invalidado */
       this->iniciar_cursor();
   }
}

template<class T> void Lista<T>::iniciar_cursor() {

   this->cursor = NULL;
}

template<class T> bool Lista<T>::avanzar_cursor() {

   if (this->cursor == NULL) {

       this->cursor = this->primero;

   } else {

       this->cursor = this->cursor->obtener_siguiente();
   }

   /* pudo avanzar si el cursor ahora apunta a un nodo */
   return (this->cursor != NULL);
}

template<class T> T Lista<T>::obtener_cursor() {

   T elemento;

   if (this->cursor != NULL) {

       elemento = this->cursor->obtener_dato();
   }

   return elemento;
}

template<class T> Lista<T>::~Lista() {

   while (this->primero != NULL) {

       Nodo<T>* a_borrar = this->primero;
       this->primero = this->primero->obtener_siguiente();

       delete a_borrar;
   }
}

template<class T> Nodo<T>* Lista<T>::obtener_nodo(unsigned int posicion) {

   Nodo<T>* actual = this->primero;
   for (unsigned int i = 1; i < posicion; i++) {

       actual = actual->obtener_siguiente();
   }

   return actual;
}

#endif /* LISTA_H_ */
