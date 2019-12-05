#ifndef ENTORNO_H
#define ENTORNO_H

#include <iostream>
#include "Textura.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include "ImageLoader.h"
#include "tejido.h"
#include "imagenes.h"
#include "dosis.h"
#include "tipodosis.h"
#include "resultadojuego.h"
#include "math.h"

class Entorno
{
    private:

    SDL_Window* window;
    SDL_Renderer* renderer;
    ImageLoader* loaderA;
    ImageLoader* loaderB;
    Textura texturas[9];
    int estadoDosisA,estadoDosisB;
    float nanobot_pos_x;
    float nanobot_pos_y;
    Tejido* tejido;
    Anticuerpo* anticuerpo_atrapado;
    int estado_inyeccion;
    int estado_atrapada;
    int estado_trayecto_nanobot;
    TTF_Font* fuente;
    SDL_Surface* texto;
    SDL_Surface* texto1;
    float desplazamiento_nanobot_x;
    float desplazamiento_nanobot_y;
    Lista<CoordenadasElemento*>* coordenadas_a_visitar;

    public:
        //PRE:-
        //POST: genera un entorno
        Entorno();
        ~Entorno();
        //PRE:-
        //POST:
        void cargar_texturas();
        //PRE:
        //POST:
        void renderizar(imagenes imagen, float x, float y);
        //PRE:
        //POST:
        bool iniciar(const char *titulo, int xPos, int yPos, int flags);
        //PRE:
        //POST:
        void renderizar_todo();
        //PRE:
        //POST:
        void limpiar();
        //PRE:
        //POST:
        void explotarDosis(dosis dosis);
        //PRE:
        //POST:
        bool dosisAExplotando();
        //PRE:
        //POST:
        bool dosisBExplotando();
        //PRE:
        //POST:
        void dibujar_lineas_entre_celulas();
        //PRE:
        //POST:
        void dibujar_celulas();
        //PRE:
        //POST:
        void dibujar_etiqueta(std::string mi_texto, float x, float y);
        //PRE:
        //POST:
        void dibujar_anticuerpos();
        //PRE:
        //POST:
        void dibujar_dosis();
        //PRE:
        //POST:
        void mutar_celulas();
        // PRE:
        // POST:
        void mover_anticuerpos();
        //PRE:
        //POST:
        void generar_anticuerpo();
        //PRE:
        //POST:
        void detector_colisiones();
        //PRE:
        //POST:
        void animar_inyeccion_dosis();
        //PRE:
        //POST:
        void animar_atrapada_anticuerpo();
        //PRE:
        //POST:
        void animar_trayecto_nanobot();
		//PRE:
		//POST:
		void inyectar_dosis(TipoDosis tipo_dosis);
		//PRE:
		//POST:
		void atrapar_anticuerpo();
		//PRE:
		//POST:
		void disparar_anticuerpo();
        //PRE:
        //POST:
        float obtener_nanobot_pos_x();
        //PRE:
        //POST:
        float obtener_nanobot_pos_y();
        //PRE:
        //POST:
        void cambiar_nanobot_pos_x(int x);
        //PRE:
        //POST:
        void cambiar_nanobot_pos_y(int y);
        //PRE:
        //POST:
        unsigned int obtener_cantidad_total_celulas();
        //PRE:
        //POST:
        unsigned int obtener_cantidad_celulas(string tipo_celula);
        //PRE:
        //POST:
        Anticuerpo* obtener_anticuerpo_atrapado();
        //PRE:
        //POST:
        bool hay_colision(float pos_x1, float pos_y1, float pos_x2, float pos_y2, int ancho_objeto1, int ancho_objeto2);
        //PRE:
        //POST:
		bool inyectando_dosis();
        //PRE:
        //POST:
		bool atrapando_anticuerpo();
		//PRE:
		//POST:
		bool realizando_trayecto_nanobot();
		//PRE:
		//POST:
        std::string estado_juego();
		//PRE:
		//POST:
		void dibujar_texto_informativo();
		// PRE:
        // POST:
        void calcular_trayecto_a_celula(unsigned int indice_celula);
        // PRE:
        // POST:
        CoordenadasElemento* obtener_coordenadas_celula_mas_cercana();
        // PRE:
        // POST:
        Lista<CoordenadasElemento*>* obtener_camino_minimo_entre_celulas(unsigned int indice_celula_mas_cercana, unsigned int indice_celula);
        // PRE:
        // POST:
        void iniciar_trayecto_a_siguiente_celula();
};

#endif // ENTORNO_H
