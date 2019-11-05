#include "ImageLoader.h"

#include "ImageLoader.h"


ImageLoader::ImageLoader(Uint8 r, Uint8 g, Uint8 b){
	this->r_value = r;
	this->g_value = g;
	this->b_value = b;
}
ImageLoader::~ImageLoader(){}

void ImageLoader::loadSprite(string firstPath, int currentSprite, SDL_Renderer *renderer, Textura* texture){

	string imagePath = firstPath + to_string(currentSprite) + ".png";

	texture->cargarDesdeArchivo(imagePath, renderer);
	texture->setColor(r_value, g_value, b_value);
}
