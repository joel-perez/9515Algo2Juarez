#include "nodo.h"
Nodo::Nodo(Dato d) {
    dato = d;
    psig = 0;
}

void Nodo::set_dato(Dato d) {
    dato = d;
}

Dato Nodo::get_dato() {
    return dato;
}

void Nodo::set_siguiente(Nodo* ps) {
    psig = ps;
}

Nodo* Nodo::get_siguiente() {
    return psig;
}
