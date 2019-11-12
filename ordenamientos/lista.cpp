#include "lista.h"

using namespace std;

Lista::Lista() {

   this->primero = NULL;
   this->tamanio = 0;
   this->cursor = NULL;
}

Lista::Lista(Lista& otra_lista) {

   this->primero = NULL;
   this->tamanio = 0;
   this->cursor = NULL;

   /* copia los elementos de otraLista */
   this->agregar(otra_lista);
}

bool Lista::esta_vacia() {

   return (this->tamanio == 0);
}

unsigned int Lista::contar_elementos() {

   return this->tamanio;
}

void Lista::agregar(int elemento) {

   this->agregar(elemento, this->tamanio + 1);
}

void Lista::agregar(int elemento, unsigned int posicion) {

   if ((posicion > 0) && (posicion <= this->tamanio + 1)) {

       Nodo* nuevo = new Nodo(elemento);

       if (posicion == 1) {

           nuevo->cambiar_siguiente(this->primero);
           this->primero = nuevo;

       } else {

           Nodo* anterior = this->obtener_nodo(posicion - 1);
           nuevo->cambiar_siguiente(anterior->obtener_siguiente());
           anterior->cambiar_siguiente(nuevo);
       }

       this->tamanio++;

       /* cualquier recorrido actual queda invalidado */
       this->iniciar_cursor();
   }

}

void Lista::agregar(Lista &otra_lista) {

   otra_lista.iniciar_cursor();
   while (otra_lista.avanzar_cursor()) {
       this->agregar(otra_lista.obtener_cursor());
   }
}

int Lista::obtener(unsigned int posicion) {

   int elemento;

   if ((posicion > 0) && (posicion <= this->tamanio)) {

       elemento = this->obtener_nodo(posicion)->obtener_dato();
   }

   return elemento;
}

void Lista::asignar(int elemento, unsigned int posicion) {

   if ((posicion > 0) && (posicion <= this->tamanio)) {

       this->obtener_nodo(posicion)->cambiar_dato(elemento);
   }
}

void Lista::remover(unsigned int posicion) {

   if ((posicion > 0) && (posicion <= this->tamanio)) {

       Nodo* removido;

       if (posicion == 1) {

           removido = this->primero;
           this->primero = removido->obtener_siguiente();

       } else {

           Nodo* anterior = this->obtener_nodo(posicion - 1);
           removido = anterior->obtener_siguiente();
           anterior->cambiar_siguiente(removido->obtener_siguiente());
       }

       delete removido;
       this->tamanio--;

       /* cualquier recorrido actual queda invalidado */
       this->iniciar_cursor();
   }
}

void Lista::iniciar_cursor() {

   this->cursor = NULL;
}

bool Lista::avanzar_cursor() {

   if (this->cursor == NULL) {

       this->cursor = this->primero;

   } else {

       this->cursor = this->cursor->obtener_siguiente();
   }

   /* pudo avanzar si el cursor ahora apunta a un nodo */
   return (this->cursor != NULL);
}

int Lista::obtener_cursor() {

   int elemento;

   if (this->cursor != NULL) {

       elemento = this->cursor->obtener_dato();
   }

   return elemento;
}

Nodo* Lista::obtener_nodo(unsigned int posicion) {

   Nodo* actual = this->primero;
   for (unsigned int i = 1; i < posicion; i++) {

       actual = actual->obtener_siguiente();
   }

   return actual;
}

Nodo* Lista::obtener_primero() {
    return primero;
}

void Lista::mostrar() {

    Nodo* nodo = primero;

    while (nodo != NULL) {
        cout << nodo->obtener_dato() << "  " << endl;
        nodo = nodo->obtener_siguiente();
    }
};

void Lista::separar(Nodo* inicio, Nodo** izquierda, Nodo** derecha) {

    Nodo* rapido = inicio->obtener_siguiente();
    Nodo* lento = inicio;

    while (rapido != NULL) {
        rapido = rapido->obtener_siguiente();
        if (rapido != NULL) {
            lento = lento->obtener_siguiente();
            rapido = rapido->obtener_siguiente();
        }
    }

    *izquierda = inicio;
    *derecha = lento->obtener_siguiente();
    lento->cambiar_siguiente(NULL);
}

Nodo* Lista::unir_ordenadas(Nodo* a, Nodo* b) {

    Nodo* resultado = NULL;

    if(a == NULL)
        return b;
    else if (b == NULL)
        return a;

    if (a->obtener_dato() <= b->obtener_dato()) {
        resultado = a;
        resultado->cambiar_siguiente(unir_ordenadas(a->obtener_siguiente(), b));
    }
    else {
        resultado = b;
        resultado->cambiar_siguiente(unir_ordenadas(a, b->obtener_siguiente()));
    }

    return resultado;
}

void Lista::mergesort(Nodo** puntero_cabecera) {

    Nodo* cabecera = *puntero_cabecera;
    Nodo* a;
    Nodo* b;

    if ((cabecera == NULL) || (cabecera->obtener_siguiente() == NULL))
        return;

    separar(cabecera, &a, &b);

    mergesort(&a);
    mergesort(&b);

    *puntero_cabecera = unir_ordenadas(a, b);
}

Lista::~Lista() {

   while (this->primero != NULL) {

       Nodo* a_borrar = this->primero;
       this->primero = this->primero->obtener_siguiente();

       delete a_borrar;
   }
}
