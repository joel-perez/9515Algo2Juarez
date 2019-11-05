//
// Created by caropistillo
//

#include "Textura.h"
#include<iostream>

using namespace std;

Textura::Textura() {
    //Inicializa
    this->textura = NULL;
    this->width = 0;
    this->height = 0;
}

Textura::~Textura() {
    //Desaloca memoria utilizada por la textura
    free();
}

bool Textura::cargarDesdeArchivo(std::string path, SDL_Renderer *renderer) {
    //Me desago de la textura actual
    free();

    //La textura final
    SDL_Texture *nuevaTextura = NULL;

    //Carga imagen de un path especifico
    SDL_Surface *superficieCargada = IMG_Load(path.c_str());
    if (superficieCargada == NULL)
    {
        cout<<"No se pudo cargar la imagen del archivo "<< string(path.c_str()) << "! SDL_image Error: "<<IMG_GetError()<<endl;
        exit(1);
    }
    else
    {
        //Color key de la imagen
        SDL_SetColorKey(superficieCargada, SDL_TRUE, SDL_MapRGB(superficieCargada->format, 0xFF, 0, 0xFF));

        //Crea textura a partir de los pixeles de la superficie
        nuevaTextura = SDL_CreateTextureFromSurface(renderer, superficieCargada);
        if (nuevaTextura == NULL)
        {
            cout<<"No se pudo crear la textura desde el archivo "<< string(path.c_str()) << "! SDL Error: " << SDL_GetError() <<endl;
        }
        else {
            //Obtener las dimensiones de la imagen cargada
            this->width = superficieCargada->w;
            this->height = superficieCargada->h;
        }

        //Me deshago de la superficie cargada antes
        SDL_FreeSurface(superficieCargada);
    }

    //Return success
    this->textura = nuevaTextura;
    return textura != NULL;
}

void Textura::free() {
    //Free texture if it exists
    if (this->textura != NULL) {
        SDL_DestroyTexture(this->textura);
        this->textura = NULL;
        this->width = 0;
        this->height = 0;
    }
}


void Textura::render(int x, int y, int renderWidth, int renderHeight, SDL_Renderer *renderer, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
{
	//SDL_Rect renderQuad = { x, y, width+100, height };
	SDL_Rect renderQuad = { x, y, renderWidth, renderHeight };

	//Set clip rendering dimensions
	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx( renderer, textura, clip, &renderQuad, angle, center, flip );
}


int Textura::getWidth() {
    return this->width;
}

int Textura::getHeight() {
    return this->height;
}

void Textura::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
	//Modulate texture
	SDL_SetTextureColorMod( textura, red, green, blue );
}
