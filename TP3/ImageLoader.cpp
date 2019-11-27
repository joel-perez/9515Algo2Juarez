#include "ImageLoader.h"

ImageLoader::ImageLoader(Uint8 r, Uint8 g, Uint8 b){
	this->r_value = r;
	this->g_value = g;
	this->b_value = b;
}
ImageLoader::~ImageLoader(){}

void ImageLoader::load_sprite(string firstPath, int currentSprite, SDL_Renderer *renderer, Textura* texture){

	string imagePath = firstPath + int_to_string(currentSprite) + ".png";

	texture->cargar_desde_archivo(imagePath, renderer);
	texture->setColor(r_value, g_value, b_value);
}
