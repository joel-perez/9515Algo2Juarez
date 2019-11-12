#ifndef IMAGE_LOADER_H
#define IMAGE_LOADER_H


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Textura.h"

using namespace std;


//A personal Image Loader for each character.
class ImageLoader{

public:
	ImageLoader(Uint8 r, Uint8 g, Uint8 b);
	~ImageLoader();

	void loadSprite(string firstPath, int currentSprite, SDL_Renderer *renderer, Textura* texture);


private:
    Uint8 r_value;
    Uint8 g_value;
    Uint8 b_value;
};


#endif // IMAGELOADER_H
