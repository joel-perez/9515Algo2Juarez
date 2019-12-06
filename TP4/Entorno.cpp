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
    tejido->asignar_dosis();
    estado_inyeccion = 1;
    estado_atrapada = 1;
    anticuerpo_atrapado = NULL;
    desplazamiento_nanobot_x = 0;
    desplazamiento_nanobot_y = 0;
    estado_trayecto_nanobot = 1;
    coordenadas_a_visitar = new Lista<CoordenadasElemento*>();
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
                } else {
                    if (TTF_Init() != 0) {
                        cerr << "SDL_ttf no pudo inicializarse: " << SDL_GetError() << endl;
                        return false;
                    } else {
                        fuente = TTF_OpenFont("fuente.ttf", 20);
                        if (fuente == NULL) {
                            cerr << "No se pudo cargar la fuente: " << SDL_GetError() << endl;
                            return false;
                        }
                    }
                }
                cargar_texturas();
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

void Entorno::cargar_texturas() {
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
    TTF_CloseFont(fuente);
    fuente = NULL;
    delete coordenadas_a_visitar;
    delete tejido;
}

void Entorno::renderizar_todo()
{
    mover_anticuerpos(); // Es correcto que este aqui?
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

    dibujar_texto_informativo();

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

bool Entorno::dosisAExplotando() {
    return estadoDosisA > 1;
}

bool Entorno::dosisBExplotando() {
    return estadoDosisB > 1;
}

bool Entorno::inyectando_dosis() {
    return estado_inyeccion > 1;
}

bool Entorno::atrapando_anticuerpo() {
    return estado_atrapada > 1;
}

bool Entorno::realizando_trayecto_nanobot() {
    return estado_trayecto_nanobot > 1;
}

void Entorno::dibujar_lineas_entre_celulas() {
    int ajuste_coordenadas = TAMANIO_CELULA / 2;
    Lista<CoordenadasRelacion*>* coordenadas_relaciones = this->tejido->obtener_coordenadas_relaciones();
    if (coordenadas_relaciones != NULL) {
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
}

void Entorno::dibujar_celulas(){
    Lista<CoordenadasElemento*>* coordenadas_celulas = tejido->obtener_coordenadas_celulas();
    coordenadas_celulas->iniciar_cursor();
	while (coordenadas_celulas->avanzar_cursor()) {
		CoordenadasElemento* coordenadas_elemento = coordenadas_celulas->obtener_cursor();
		renderizar(coordenadas_elemento->obtener_tipo(), coordenadas_elemento->obtener_pos_x(), coordenadas_elemento->obtener_pos_y());
		dibujar_etiqueta(int_to_string(coordenadas_elemento->obtener_indice()), coordenadas_elemento->obtener_pos_x(), coordenadas_elemento->obtener_pos_y());
    }
}

void Entorno::dibujar_etiqueta(string mi_texto, float x, float y) {
    SDL_Color color = { 255, 255, 255, 255 };
    TTF_Font* mi_fuente = TTF_OpenFont("fuente.ttf", 30);
    texto = TTF_RenderText_Blended(mi_fuente, mi_texto.c_str(), color);
    TTF_CloseFont(mi_fuente);
    mi_fuente = NULL;
    SDL_Texture* mi_textura = SDL_CreateTextureFromSurface(renderer, texto);
    SDL_FreeSurface(texto);
    SDL_Rect renderQuad = { static_cast<int>(x), static_cast<int>(y - 20), 20, 20 };
    SDL_Point center = {10, 10};
    SDL_RenderCopyEx(renderer, mi_textura, NULL, &renderQuad, 0, &center, SDL_FLIP_NONE);
    SDL_DestroyTexture(mi_textura);
    mi_textura = NULL;
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
                    tejido->empeorar_estado(adyacente_actual);
            }
        }
        else if (vertice_actual->obtener_elemento()->obtener_tipo() != TIPO_CELULA_S)
            tejido->empeorar_estado(vertice_actual);
    }
}

void Entorno::mover_anticuerpos(){
    Lista<Anticuerpo*>* anticuerpos = tejido->obtener_lista_anticuerpos();
    anticuerpos->iniciar_cursor();
    while (anticuerpos->avanzar_cursor()) {
        Anticuerpo* actual = anticuerpos->obtener_cursor();
        if (actual->obtener_esta_atrapado())
            actual->establecer_posiciones(nanobot_pos_x, nanobot_pos_y);
        else if (actual->obtener_esta_siendo_disparado()) {
            // TODO: Modificar la posicion en base a la direccion del nanobot
            actual->establecer_posiciones(actual->obtener_posicion_x(), actual->obtener_posicion_y() - 10);
            if (actual->obtener_posicion_x() <= 0 || actual->obtener_posicion_x() >= SCREEN_WIDTH ||
                actual->obtener_posicion_y() <= 0 || actual->obtener_posicion_y() >= SCREEN_HEIGHT)
                actual->cambiar_esta_siendo_disparado(false);
        }
        else
            actual->posicion_aleatoria();
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
            if (hay_colision(celula_x, celula_y, anticuerpo_x, anticuerpo_y, CELULA_SIZE, ANTICUERPO_HEIGHT)
                && !anticuerpo_actual->obtener_esta_atrapado()) {
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

void Entorno::animar_inyeccion_dosis() {
    if(estado_inyeccion <= TOTAL_FRAMES_INYECCION) {
        ++estado_inyeccion;
    } else {
        estado_inyeccion = 1;
    }
}

void Entorno::animar_atrapada_anticuerpo() {
    if(estado_atrapada <= TOTAL_FRAMES_ATRAPADA) {
        ++estado_atrapada;
    } else {
        estado_atrapada = 1;
    }
}

void Entorno::animar_trayecto_nanobot() {
    if(estado_trayecto_nanobot <= TOTAL_FRAMES_TRAYECTO_NANOBOT) {
        ++estado_trayecto_nanobot;
        nanobot_pos_x += desplazamiento_nanobot_x;
        nanobot_pos_y += desplazamiento_nanobot_y;
    } else {
        estado_trayecto_nanobot = 1;
        desplazamiento_nanobot_x = 0;
        desplazamiento_nanobot_y = 0;
    }
}

void Entorno::inyectar_dosis(TipoDosis tipo_dosis) {
    Lista<Vertice*>* vertices = this->tejido->obtener_grafo()->obtener_vertices();
    Vertice* celula;
    bool se_produjo_colision = false;
    vertices->iniciar_cursor();
    while (vertices->avanzar_cursor() && !se_produjo_colision) {
        celula = vertices->obtener_cursor();
        if (celula != NULL) {
            Elemento* elemento_actual = celula->obtener_elemento();
            if (elemento_actual != NULL) {
                float celula_pos_x = elemento_actual->obtener_posicion_x();
                float celula_pos_y = elemento_actual->obtener_posicion_y();
                if (hay_colision(nanobot_pos_x, nanobot_pos_y, celula_pos_x, celula_pos_y, NANOBOT_WIDTH, TAMANIO_CELULA)) {
                    se_produjo_colision = true;
                }
            }
        }
    }
    if (se_produjo_colision) {
        if (tipo_dosis == A) {
            this->tejido->impacto_destructivo(celula);
        }
        else if (tipo_dosis == B) {
            this->tejido->impacto_constructivo(celula);
        }
    }
}

void Entorno::atrapar_anticuerpo() {
    Lista<Anticuerpo*>* anticuerpos = tejido->obtener_lista_anticuerpos();
    anticuerpos->iniciar_cursor();
    while (anticuerpos->avanzar_cursor()) {
        Anticuerpo* anticuerpo_actual = anticuerpos->obtener_cursor();
        float anticuerpo_x = anticuerpo_actual->obtener_posicion_x();
        float anticuerpo_y = anticuerpo_actual->obtener_posicion_y();
        if (hay_colision(nanobot_pos_x, nanobot_pos_y, anticuerpo_x, anticuerpo_y, NANOBOT_WIDTH, ANTICUERPO_WIDTH)
            && anticuerpo_atrapado == NULL) {
            anticuerpo_actual->cambiar_esta_atrapado(true);
            anticuerpo_atrapado = anticuerpo_actual;
            anticuerpos->avanzar_cursor() == false;
        }
    }
}

void Entorno::disparar_anticuerpo() {
    if (anticuerpo_atrapado != NULL) {
        anticuerpo_atrapado->cambiar_esta_atrapado(false);
        anticuerpo_atrapado->cambiar_esta_siendo_disparado(true);
        anticuerpo_atrapado = NULL;
    }
}

bool Entorno::hay_colision(float pos_x1, float pos_y1, float pos_x2, float pos_y2, int ancho_objeto1, int ancho_objeto2) {
    return (pos_x1 >= pos_x2 - ancho_objeto1) &&
           (pos_x1 <= pos_x2 + ancho_objeto2) &&
           (pos_y1 >= pos_y2 - ancho_objeto1) &&
           (pos_y1 <= pos_y2 + ancho_objeto2);
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

void Entorno::dibujar_texto_informativo(){
    SDL_Color color = { 0, 0, 0, 0 };
    string mi_texto = "TP4 NANOBOT-GRUPO: SOBRECARGADOS --dosis A: "
            + int_to_string(this->tejido->obtener_dosis_a_disponibles())
            + " --dosis B: " + int_to_string(this->tejido->obtener_dosis_b_disponibles())
            + " --celulas S: " + float_to_string(this->obtener_cantidad_celulas("S"))
            + " --celulas X: " + float_to_string(this->obtener_cantidad_celulas("X"))
            + " --celulas Y: " + float_to_string(this->obtener_cantidad_celulas("Y"))
            + " --celulas Z: " + float_to_string(this->obtener_cantidad_celulas("Z"))
            + " --Estado del juego: " + estado_juego();
    texto = TTF_RenderText_Blended(fuente, mi_texto.c_str(), color);
    SDL_Texture* mi_textura = SDL_CreateTextureFromSurface(renderer, texto);
    SDL_FreeSurface(texto);
    SDL_Rect renderQuad = { 10, 10, 950, 48 };
    SDL_Point center = {10, 10};
    SDL_RenderCopyEx(renderer, mi_textura, NULL, &renderQuad, 0, &center, SDL_FLIP_NONE);
    SDL_DestroyTexture(mi_textura);
    mi_textura = NULL;
}

string Entorno::estado_juego(){
    unsigned int total_celulas = obtener_cantidad_total_celulas();
    unsigned int cant_celulas_s = obtener_cantidad_celulas(TIPO_CELULA_S);
    unsigned int cant_celulas_z = obtener_cantidad_celulas(TIPO_CELULA_Z);
    if (100 * cant_celulas_s / (float) total_celulas == 100)
        return "GANASTE EL JUEGO";
    else if (100 * cant_celulas_z / (float) total_celulas > 50)
        return "PERDISTE EL JUEGO";
    return "JUGANDO";
}

CoordenadasElemento* Entorno::obtener_coordenadas_celula_mas_cercana() {
    CoordenadasElemento* resultado = NULL;
    float distancia_menor = 0;
    float pos_x_mas_cercana = 0;
    float pos_y_mas_cercana = 0;
    unsigned int indice_celula_mas_cercana = 0;
    bool primera_comparacion = true;
    Grafo* grafo = tejido->obtener_grafo();
    Lista<Vertice*>* vertices = grafo->obtener_vertices();
    vertices->iniciar_cursor();
    while(vertices->avanzar_cursor()) {
        Vertice* vertice_actual = vertices->obtener_cursor();
        unsigned int indice_celula_actual = vertice_actual->obtener_indice();
        Elemento* elemento_actual = vertice_actual->obtener_elemento();
        float posicion_x = elemento_actual->obtener_posicion_x();
        float posicion_y = elemento_actual->obtener_posicion_y();
        float distancia = sqrt(pow(posicion_x - nanobot_pos_x, 2) + pow(posicion_y - nanobot_pos_y, 2));
        if (distancia < distancia_menor || primera_comparacion) {
            primera_comparacion = false;
            distancia_menor = distancia;
            indice_celula_mas_cercana = indice_celula_actual;
            pos_x_mas_cercana = posicion_x;
            pos_y_mas_cercana = posicion_y;
        }
    }
    resultado = new CoordenadasElemento(pos_x_mas_cercana, pos_y_mas_cercana, CELULA_S, indice_celula_mas_cercana);
    return resultado;
}

Lista<CoordenadasElemento*>* Entorno::obtener_camino_minimo_entre_celulas(unsigned int indice_celula_mas_cercana, unsigned int indice_celula) {
    Lista<CoordenadasElemento*>* resultado = new Lista<CoordenadasElemento*>();

    Grafo* grafo = tejido->obtener_grafo();
    Vertice* vertice_origen = grafo->obtener_vertice_por_indice(indice_celula_mas_cercana);
    Vertice* vertice_destino = grafo->obtener_vertice_por_indice(indice_celula);
    if (vertice_origen != NULL && vertice_destino != NULL) {
        bool origen_destino_directamente_unidos = false;
        bool destino_origen_directamente_unidos = false;
        Lista<Arista*>* adyacentes_origen = vertice_origen->obtener_adyacentes();
        adyacentes_origen->iniciar_cursor();
        while(adyacentes_origen->avanzar_cursor() && !origen_destino_directamente_unidos) {
            Arista* adyacente = adyacentes_origen->obtener_cursor();
            origen_destino_directamente_unidos = adyacente->obtener_destino()->obtener_indice() == indice_celula;
        }
        Lista<Arista*>* adyacentes_destino = vertice_destino->obtener_adyacentes();
        adyacentes_destino->iniciar_cursor();
        while(adyacentes_destino->avanzar_cursor() && !destino_origen_directamente_unidos) {
            Arista* adyacente = adyacentes_destino->obtener_cursor();
            destino_origen_directamente_unidos = adyacente->obtener_destino()->obtener_indice() == indice_celula;
        }

        if (origen_destino_directamente_unidos || destino_origen_directamente_unidos) {
            Elemento* elemento_destino = vertice_destino->obtener_elemento();
            resultado->agregar(new CoordenadasElemento(elemento_destino->obtener_posicion_x(), elemento_destino->obtener_posicion_y(), CELULA_S, indice_celula));
        } else {
            // TODO: Corregir el dijkstra para que no se cuelgue cuando hay nodos que fueron borrados...
            // TODO: Corregir el dijkstra para que devuelva una lista de celulas a visitar...
            // int peso_minimo = grafo->obtener_camino_minimo(vertice_origen, vertice_destino);
            // cout << "Peso minimo entre " << indice_celula_mas_cercana << " y " << indice_celula << " tiene peso " << peso_minimo << endl;
        }
    }

    return resultado;
}

void Entorno::calcular_trayecto_a_celula(unsigned int indice_celula) {
    CoordenadasElemento* coordenadas_celula_mas_cercana = obtener_coordenadas_celula_mas_cercana();
    unsigned int indice_celula_mas_cercana = coordenadas_celula_mas_cercana->obtener_indice();
    coordenadas_a_visitar->agregar(coordenadas_celula_mas_cercana);
    if (indice_celula_mas_cercana != indice_celula) {
        Lista<CoordenadasElemento*>* camino_minimo_entre_celulas = obtener_camino_minimo_entre_celulas(indice_celula_mas_cercana, indice_celula);
        camino_minimo_entre_celulas->iniciar_cursor();
        while (camino_minimo_entre_celulas->avanzar_cursor()) {
            coordenadas_a_visitar->agregar(camino_minimo_entre_celulas->obtener_cursor());
        }
    }
}

void Entorno::iniciar_trayecto_a_siguiente_celula() {
    if (coordenadas_a_visitar != NULL && coordenadas_a_visitar->contar_elementos() > 0) {
        CoordenadasElemento* coordenadas_actuales = coordenadas_a_visitar->obtener(1);
        this->desplazamiento_nanobot_x = (coordenadas_actuales->obtener_pos_x() - nanobot_pos_x) / TOTAL_FRAMES_TRAYECTO_NANOBOT;
        this->desplazamiento_nanobot_y = (coordenadas_actuales->obtener_pos_y() - nanobot_pos_y) / TOTAL_FRAMES_TRAYECTO_NANOBOT;
        coordenadas_a_visitar->remover(1);
        animar_trayecto_nanobot();
    }
}
