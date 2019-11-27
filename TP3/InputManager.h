#ifndef INPUTMANAGER_H_
#define INPUTMANAGER_H_

#include <iostream>
#include "SDL2/SDL.h"
#include "InputTable.h"

class InputManager {
public:
	InputManager();
	static InputManager* get_instance();
	void update();
	bool is_key_down(int key);
	bool is_key_up(int key);
	bool is_key_pressed(KeyboardKey key);
	bool is_holding_key(int key);
	bool quit_requested();

private:
	static InputManager* instance;
	const uint8_t* keyboard;
	bool quit;

	uint8_t key_status[KEYBOARD_SIZE];
	uint8_t key_hold[KEYBOARD_SIZE];
};

#endif /* INPUTMANAGER_H_ */
