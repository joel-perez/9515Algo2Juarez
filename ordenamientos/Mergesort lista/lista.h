#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"

class Lista {
  private:
    Nodo* primero;
    unsigned int tamanio;
    Nodo* cursor;

  public:
    //post: Lista vacía.
    Lista();

    //post: Lista que tiene los mismos elementos que otra_lista. La instancia resulta en una copia de otra_lista.
    Lista(Lista& otraLista);

    //post: indica si la Lista tiene algún elemento.
    bool esta_vacia();

    //post: devuelve la cantidad de elementos que tiene la Lista.
    unsigned int contar_elementos();

    //post: agrega el elemento al final de la Lista, en la posición:
    //contar_elementos() + 1.

    void agregar(int elemento);

    //pre : posición pertenece al intervalo: [1, contar_elementos() + 1]
    //post: agrega el elemento en la posición indicada.
    void agregar(int elemento, unsigned int posicion);

    //post: agrega todos los elementos de otra_lista a partir de la posición contar_elementos() + 1.
    void agregar(Lista &otra_lista);

    //pre : posición pertenece al intervalo: [1, contarElementos()]
    //post: devuelve el elemento en la posición indicada.
    int obtener(unsigned int posicion);

    //pre : posición pertenece al intervalo: [1, contarElementos()]
    //post: cambia el elemento en la posición indicada por el elemento dado.
    void asignar(int elemento, unsigned int posicion);

    //pre : posición pertenece al intervalo: [1, contarElementos()]
    //post: remueve de la Lista el elemento en la posición indicada.
    void remover(unsigned int posicion);

    //post: deja el cursor de la Lista preparado para hacer un nuevo recorrido sobre sus elementos.
    void iniciar_cursor();

    /* pre : se ha iniciado un recorrido (invocando el método iniciarCursor()) y desde entonces
             no se han agregado o removido elementos de la Lista.
       post: mueve el cursor y lo posiciona en el siguiente elemento del recorrido. El valor de retorno
             indica si el cursor quedó posicionado sobre un elemento o no (en caso de que la Lista esté
             vacía o no existan más elementos por recorrer).
    */
    bool avanzar_cursor();

    /* pre : el cursor está posicionado sobre un elemento de la Lista
             (fue invocado el método avanzarCursor() y devolvió true)
       post: devuelve el elemento en la posición del cursor.
    */
    int obtener_cursor();

    // pre : posición pertenece al intervalo: [1, contarElementos()]
    // post: devuelve el nodo en la posición indicada.
    Nodo* obtener_nodo(unsigned int posicion);

    // post: devuelve un puntero al primer elemento.
    Nodo* obtener_primero();

    // post: imprime por pantalla los elementos de la lista.
    void mostrar();

    // post: divide la lista por la mitad, si el numero de elementos es impar el sobrante queda a la izquierda.
    void separar(Nodo* origen, Nodo** izquierda, Nodo** derecha);

    // post: toma dos listas ordenadas ascendentemente, las une y devuelve un puntero a la nueva lista.
    Nodo* unir_ordenadas(Nodo* a, Nodo* b);

    // post: ordena la lista modificando los punteros, recibiendo como parametro un puntero cabecera.
    void mergesort(Nodo** puntero_cabecera);

    // post: ordena la lista modificando los punteros.
    void mergesort();

    // post: libera los recursos asociados a la Lista.
    ~Lista();
};

#endif
