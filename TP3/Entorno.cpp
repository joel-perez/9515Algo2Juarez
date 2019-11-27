#include "Entorno.h"

using namespace std;

Entorno::Entorno() {
    estadoDosisA = 1;
    estadoDosisB = 1;
    loaderA = new ImageLoader(COMMON_RED, COMMON_GREEN, COMMON_BLUE);
    loaderB = new ImageLoader(SECONDARY_RED, SECONDARY_GREEN, SECONDARY_BLUE);
    nanobot_pos_x = 0;
    nanobot_pos_y = SCREEN_HEIGHT - NANOBOT_HEIGHT;
    tejido = new Tejido();
    tejido->cargar_archivo();
}

bool Entorno::iniciar(const char *title, int xpos, int ypos, int flags) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        cerr << "SDL no se pudo inicializar." << endl;
        return false;
    }
    else
    {
        window = SDL_CreateWindow(title, xpos, ypos, SCREEN_WIDTH, SCREEN_HEIGHT, flags);
        if (window == 0)
        {
            cerr << "Fallo al crear ventana." << endl;
            return false;
        } else {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (renderer == 0) {
                cerr << "Fallo al crear Renderer" << endl;
                return false;
            } else {
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags)) {
                    cerr << "SDL_image no pudo inicializarse." << endl;
                    return false;
                }
                cargarTexturas();
            }
        }
    }
    // everything inited successfully,
    return true;
}

void Entorno::renderizar(imagenes imagen, float x, float y) {
    switch(imagen) {
    case FONDO:
        texturas[FONDO].render(x, y, SCREEN_WIDTH, SCREEN_HEIGHT, renderer);
        break;
    case NANOBOT:
        texturas[NANOBOT].render(x, y, NANOBOT_WIDTH, NANOBOT_HEIGHT, renderer);
        break;
    case CELULA_S:
        texturas[CELULA_S].render(x, y, CELULA_SIZE, CELULA_SIZE, renderer);
        break;
    case CELULA_X:
        texturas[CELULA_X].render(x, y, CELULA_SIZE, CELULA_SIZE, renderer);
        break;
    case CELULA_Y:
        texturas[CELULA_Y].render(x, y, CELULA_SIZE, CELULA_SIZE, renderer);
        break;
    case CELULA_Z:
        texturas[CELULA_Z].render(x, y, CELULA_SIZE, CELULA_SIZE, renderer);
        break;
    case ANTICUERPO:
        texturas[ANTICUERPO].render(x, y, ANTICUERPO_WIDTH, ANTICUERPO_HEIGHT, renderer);
        break;
    case DOSIS_A:
        if(estadoDosisA < LAST_DOSIS_SPRITE)
            texturas[DOSIS_A].render(x, y, DOSIS_WIDTH, DOSIS_HEIGHT, renderer);
        break;
    case DOSIS_B:
        if(estadoDosisB < LAST_DOSIS_SPRITE)
            texturas[DOSIS_B].render(x, y, DOSIS_WIDTH, DOSIS_HEIGHT, renderer);
        break;
    }
}

void Entorno::cargarTexturas() {
    for(int i = 0; i < 7; i++) {
        texturas[i].cargar_desde_archivo(PATHS[i], renderer);
    }
    loaderA->load_sprite(DOSIS_PATH, estadoDosisA, renderer, &texturas[DOSIS_A]);
    loaderB->load_sprite(DOSIS_PATH, estadoDosisB, renderer, &texturas[DOSIS_B]);
}

Entorno::~Entorno()
{
    window = NULL;
    renderer = NULL;
    delete tejido;
}

void Entorno::renderizarTodo()
{
    tejido->mover_anticuerpos(); // Es correcto que este aqui?
    detector_colisiones();       // Es correcto que este aqui?

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer); // clear the renderer to the draw color
    renderizar(FONDO, 0, 0);
    renderizar(NANOBOT, nanobot_pos_x, nanobot_pos_y);

    //Prepara el Draw para dibujar una linea negra
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    //Inserte codigo para dibujar lineas
    dibujar_lineas_entre_celulas();
    //Inserte codigo para renderizar imagenes
    dibujar_celulas();
    dibujar_anticuerpos();
    dibujar_dosis();

    SDL_RenderPresent(renderer); // draw to the screen
}

void Entorno::limpiar()
{
    for(int i = 0; i < 7; i++)
        texturas[i].free();
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void Entorno::explotarDosis(dosis dosis)
{
    switch(dosis) {
    case DosisA:
        if(estadoDosisA <= LAST_DOSIS_SPRITE)
        {
            this->loaderA->load_sprite(DOSIS_PATH, estadoDosisA, renderer, &texturas[DOSIS_A]);
            ++estadoDosisA;
        } else {
            estadoDosisA = 1;
            this->loaderA->load_sprite(DOSIS_PATH, estadoDosisA, renderer, &texturas[DOSIS_A]);
        }
        break;
    case DosisB:
        if(estadoDosisB <= LAST_DOSIS_SPRITE)
        {
            this->loaderB->load_sprite(DOSIS_PATH, estadoDosisB, renderer, &texturas[DOSIS_B]);
            ++estadoDosisB;
        } else {
            estadoDosisB = 1;
            this->loaderB->load_sprite(DOSIS_PATH, estadoDosisB, renderer, &texturas[DOSIS_B]);
        }
    }
}

bool Entorno::dosisAExplotando()
{
    return estadoDosisA > 1;
}

bool Entorno::dosisBExplotando()
{
    return estadoDosisB > 1;
}

void Entorno::dibujar_lineas_entre_celulas() {
    int ajuste_coordenadas = TAMANIO_CELULA / 2;
    Lista<CoordenadasRelacion*>* coordenadas_relaciones = this->tejido->obtener_coordenadas_relaciones();
    coordenadas_relaciones->iniciar_cursor();
	while (coordenadas_relaciones->avanzar_cursor()) {
		CoordenadasRelacion* coordenadas_relacion = coordenadas_relaciones->obtener_cursor();
		SDL_RenderDrawLine(renderer,
                           coordenadas_relacion->obtener_inicio_x() + ajuste_coordenadas,
                           coordenadas_relacion->obtener_inicio_y() + ajuste_coordenadas,
                           coordenadas_relacion->obtener_destino_x() + ajuste_coordenadas,
                           coordenadas_relacion->obtener_destino_y() + ajuste_coordenadas);
    }
    delete coordenadas_relaciones;
}

void Entorno::dibujar_celulas(){
    Lista<CoordenadasElemento*>* coordenadas_celulas = tejido->obtener_coordenadas_celulas();
    coordenadas_celulas->iniciar_cursor();
	while (coordenadas_celulas->avanzar_cursor()) {
		CoordenadasElemento* coordenadas_elemento = coordenadas_celulas->obtener_cursor();
		renderizar(coordenadas_elemento->obtener_tipo(), coordenadas_elemento->obtener_pos_x(), coordenadas_elemento->obtener_pos_y());
    }
}

void Entorno::dibujar_anticuerpos(){
    Lista<CoordenadasElemento*>* coordenadas_anticuerpos = tejido->obtener_coordenadas_anticuerpos();
    coordenadas_anticuerpos->iniciar_cursor();
	while (coordenadas_anticuerpos->avanzar_cursor()) {
		CoordenadasElemento* coordenadas_elemento = coordenadas_anticuerpos->obtener_cursor();
		renderizar(coordenadas_elemento->obtener_tipo(), coordenadas_elemento->obtener_pos_x(), coordenadas_elemento->obtener_pos_y());
    }
}

void Entorno::dibujar_dosis() {
    // renderizar(DOSIS_A, 250, 250); // TODO: Mejorar esto... es solo una prueba para ver como explota con la tecla A
    // renderizar(DOSIS_B, 250, 350); // TODO: Mejorar esto... es solo una prueba para ver como explota con la tecla B
}

void Entorno::mutar_celulas() {
    Lista<Vertice*>* vertices = tejido->obtener_grafo()->obtener_vertices();
    vertices->iniciar_cursor();
    while(vertices->avanzar_cursor()) {
        Vertice* vertice_actual = vertices->obtener_cursor();
        if (vertice_actual->obtener_elemento()->obtener_tipo() == TIPO_CELULA_Z) {
            Lista<Arista*>* adyacentes = vertice_actual->obtener_adyacentes();
            adyacentes->iniciar_cursor();
            while (adyacentes->avanzar_cursor()){
                Vertice* adyacente_actual = adyacentes->obtener_cursor()->obtener_destino();
                if (adyacente_actual->obtener_elemento()->obtener_tipo() == TIPO_CELULA_S)
                    tejido->empeorar_estado(adyacente_actual->obtener_indice());
            }
        }
        else if (vertice_actual->obtener_elemento()->obtener_tipo() != TIPO_CELULA_S)
            tejido->empeorar_estado(vertice_actual->obtener_indice());
    }
}

void Entorno::generar_anticuerpo() {
    this->tejido->generar_anticuerpo();
}

void Entorno::detector_colisiones() {
    // Celulas con anticuerpos
    Lista<Vertice*>* vertices = tejido->obtener_grafo()->obtener_vertices();
    vertices->iniciar_cursor();
    while(vertices->avanzar_cursor()) {
        Vertice* vertice_actual = vertices->obtener_cursor();
        Elemento* elemento_actual = vertice_actual->obtener_elemento();
        float celula_x = elemento_actual->obtener_posicion_x();
        float celula_y = elemento_actual->obtener_posicion_y();
        string tipo_elemento = elemento_actual->obtener_tipo();
        int indice_anticuerpo = 0;
        bool debe_remover_anticuerpo = false;
        Lista<Anticuerpo*>* lista_anticuerpos = tejido->obtener_lista_anticuerpos();
        lista_anticuerpos->iniciar_cursor();
        while (lista_anticuerpos->avanzar_cursor() && !debe_remover_anticuerpo) {
            Anticuerpo* anticuerpo_actual = lista_anticuerpos->obtener_cursor();
            float anticuerpo_x = anticuerpo_actual->obtener_posicion_x();
            float anticuerpo_y = anticuerpo_actual->obtener_posicion_y();
            if (hay_colision(celula_x, celula_y, anticuerpo_x, anticuerpo_y, ANTICUERPO_HEIGHT, CELULA_SIZE)) {
                if (tipo_elemento != TIPO_CELULA_S){
                    debe_remover_anticuerpo = true;
                    Elemento* nuevo = new Celula(TIPO_CELULA_S,
                                                 elemento_actual->obtener_posicion_x(),
                                                 elemento_actual->obtener_posicion_y());
                    vertice_actual->cambiar_elemento(nuevo);
                    delete elemento_actual;
                }
            }
            indice_anticuerpo++;
        }
        if (debe_remover_anticuerpo){
            lista_anticuerpos->remover(indice_anticuerpo);
        }
    }
}

bool Entorno::hay_colision(float pos_x1, float pos_y1, float pos_x2, float pos_y2, int ancho_objeto1, int ancho_objeto2) {
    int ancho_objeto = ancho_objeto1;
    if (ancho_objeto2 > ancho_objeto1)
        ancho_objeto = ancho_objeto2;
    return (pos_x1 >= pos_x2 - ancho_objeto) &&
           (pos_x1 <= pos_x2 + ancho_objeto) &&
           (pos_y1 >= pos_y2 - ancho_objeto) &&
           (pos_y1 <= pos_y2 + ancho_objeto);
}


float Entorno::obtener_nanobot_pos_x() {
     return nanobot_pos_x;
}

float Entorno::obtener_nanobot_pos_y() {
    return nanobot_pos_y;
}

void Entorno::cambiar_nanobot_pos_x(int x) {
    nanobot_pos_x = x;
}

void Entorno::cambiar_nanobot_pos_y(int y) {
     nanobot_pos_y = y;
}

unsigned int Entorno::obtener_cantidad_total_celulas(){
    return tejido->obtener_cantidad_total_celulas();
}

unsigned int Entorno::obtener_cantidad_celulas(string tipo_celula){
    return tejido->obtener_cantidad_celulas(tipo_celula);
}
