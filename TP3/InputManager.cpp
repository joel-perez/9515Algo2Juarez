#include "InputManager.h"

InputManager* InputManager::instance = nullptr;

InputManager::InputManager() {
	this->quit = false;
	this->keyboard = SDL_GetKeyboardState(nullptr);

	for(int i = 0; i < KEYBOARD_SIZE; i++){
		this->key_status[i] = 0;
		this->key_hold[i] = 0;
	}
}

InputManager* InputManager::get_instance() {
	if(!instance) {
		instance = new InputManager();
	}

	return instance;
}

void InputManager::update() {

	SDL_Event event;
	while(SDL_PollEvent(&event)) {

		switch (event.type) {
		case SDL_QUIT:
			this->quit = true;
			break;

		case SDL_KEYDOWN:



			if(event.key.repeat)
				this->key_hold[SDL_GetScancodeFromKey(event.key.keysym.sym)] = 1;

			this->key_status[SDL_GetScancodeFromKey(event.key.keysym.sym)] = 1;
			break;

		case SDL_KEYUP:

			this->key_status[SDL_GetScancodeFromKey(event.key.keysym.sym)] = 0;
			this->key_hold[SDL_GetScancodeFromKey(event.key.keysym.sym)] = 0;
			break;

		default:
			break;
		}
	}
}

bool InputManager::is_key_down(int key) {
	if(key < 0 || key >= KEYBOARD_SIZE)
		return false;

	return this->key_status[key];
}

bool InputManager::is_key_up(int key) {
	if(key < 0 || key >= KEYBOARD_SIZE)
		return false;

	return this->key_status[key];
}

bool InputManager::is_holding_key(int key){
	return this->key_hold[key];
}

bool InputManager::is_key_pressed(KeyboardKey key) {
	if(!(this->keyboard))
		return false;

	int sdlKey = static_cast<int>(key);

	if(this->keyboard[sdlKey])
		return true;

	return false;
}

bool InputManager::quit_requested() {
	return this->quit;
}
