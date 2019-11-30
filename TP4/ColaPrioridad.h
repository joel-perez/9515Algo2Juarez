#ifndef COLAPRIORIDAD_H
#define COLAPRIORIDAD_H
#include <string>
#include "Nodo.h"

template<class T> class ColaPrioridad {
private:
	Nodo<T>* frente;
	Nodo<T>* fondo;
public:
	/*
	 * post: instancia de Cola vacía y lista para ser usada.
	 */
	ColaPrioridad();
	/*
	 * pre: el nodo debe existir y el valor de la prioridad debe ser mayor o igual a cero
	 * post: Actualiza el valor de la prioridad del nodo y lo ordena en la cola. Si el valor de la prioridad
	 * no es la indicada no hace nada.
	 */
	void actualizar_valor(T vertice, unsigned int prioridad);
	/*
	 * post: devuelve true si la cola esta vacia y false si no.
	 */
	bool esta_vacia();
	/*
	 * post: agrega elemento en el fondo de la Cola.
	 */
	void acolar(T elemento, unsigned int prioridad);
	/*
	 * pre : la Cola no está vacía.
	 * post: remueve el frente de la Cola y lo devuelve.
	 */
	T desacolar();
	/*
	 * pre : la Cola no está vacía.
	 * post: devuelve el frente de la Cola.
	 */
	T obtener_frente();
	/*
	 * post: Ordena la cola segun la prioridad de cada nodo
	 */
	void ordenar();
	/*
	 * post: remueve todos los elementos y libera los recursos utilizados.
	 */
	~ColaPrioridad();
};
template<class T>
ColaPrioridad<T>::ColaPrioridad() {
	this->frente = NULL;
	this->fondo = NULL;
}
template<class T>
bool ColaPrioridad<T>::esta_vacia() {
	return (this->frente == NULL);
}
template<class T>
void ColaPrioridad<T>::acolar(T elemento, unsigned int prioridad) {
	if (prioridad >= 0) {
		Nodo<T>* nuevo_fondo = new Nodo<T>(elemento);
		nuevo_fondo->cambiar_prioridad(prioridad);
		if (this->esta_vacia()) {
			this->frente = nuevo_fondo;
			this->fondo = nuevo_fondo;
		} else if (this->frente->obtener_prioridad() > prioridad) {
			Nodo<T>* nodo_siguiente = this->frente;
			this->frente = nuevo_fondo;
			nuevo_fondo->cambiar_siguiente(nodo_siguiente);
		} else {
			Nodo<T>* Cambiar = this->frente;
			while (Cambiar->obtener_siguiente() != NULL && Cambiar->obtener_siguiente()->obtener_prioridad() < prioridad) {
				Cambiar = Cambiar->obtener_siguiente();
			}
			Nodo<T>* siguiente = Cambiar->obtener_siguiente();
			Cambiar->cambiar_siguiente(nuevo_fondo);
			nuevo_fondo->cambiar_siguiente(siguiente);
			if (siguiente == NULL) {
				this->fondo = nuevo_fondo;
			}
		}
	}
}
template<class T>
void ColaPrioridad<T>::actualizar_valor(T vertice, unsigned int valor) {
	Nodo<T>* nodo_buscado = this->frente;
	bool encontrado = (this->frente->obtener_dato() == vertice);
	while (nodo_buscado != NULL && !encontrado) {
		nodo_buscado = nodo_buscado->obtener_siguiente();
		encontrado = (nodo_buscado->obtener_dato() == vertice);
	}
	nodo_buscado->cambiar_prioridad(valor);
	this->ordenar();
}
template<class T>
void ColaPrioridad <T> :: ordenar(){
	Nodo<T>* anterior = this->frente;
	unsigned int prioridad_anterior;
	T dato_anterior;

	while (anterior->obtener_siguiente() != NULL) {
		Nodo<T>* siguiente = anterior->obtener_siguiente();
		while (siguiente != NULL) {
			if (anterior->obtener_prioridad() > siguiente->obtener_prioridad()) {
				prioridad_anterior = anterior->obtener_prioridad();
				dato_anterior = anterior->obtener_dato();

				anterior->cambiar_prioridad(siguiente->obtener_prioridad());
				anterior->cambiar_dato(siguiente->obtener_dato());

				siguiente->cambiar_prioridad(prioridad_anterior);
				siguiente->cambiar_dato(dato_anterior);
			}
			siguiente = siguiente->obtener_siguiente();
		}
		anterior = anterior->obtener_siguiente();
	}
}
template<class T>
T ColaPrioridad<T>::desacolar() {
	if (this->esta_vacia()) {
		throw std::string("No se puede desacolar, la cola está vacía.");
	}
	Nodo<T>* frente_anterior = this->frente;
	this->frente = frente_anterior->obtener_siguiente();
	if (this->frente == NULL) {
		this->fondo = NULL;
	}
	T elemento = frente_anterior->obtener_dato();
	delete frente_anterior;
	return elemento;
}
template<class T>
T ColaPrioridad<T>::obtener_frente() {
	if (this->esta_vacia()) {
		throw std::string(
				"No se puede obtener el frente, la cola está vacía.");
	}
	T elemento = this->frente->obtener_dato();
	return elemento;
}

template<class T>
ColaPrioridad<T>::~ColaPrioridad() {
	while (!this->esta_vacia()) {
		this->desacolar();
	}
}

#endif // COLAPRIORIDAD_H
