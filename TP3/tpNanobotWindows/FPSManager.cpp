//
// Created by caropistillo
//

#include "FPSManager.h"

FPSManager::FPSManager(int screenFPS) {
	s = 1000 / screenFPS;
	delta = 0;
	elapsedTime = 0;
	delayTime = 0;
	t1 = 0;
	t2 = 0;
}

void FPSManager::start() {
	t1 = SDL_GetTicks();
}

void FPSManager::stop() {
	t2 = SDL_GetTicks();
	elapsedTime = t2 - t1 + delta;
	delayTime = s - elapsedTime;
	if(elapsedTime < s) {
		SDL_Delay(delayTime);
		delta = SDL_GetTicks() - t2 - delayTime;
	} else
		delta = 0;
}
