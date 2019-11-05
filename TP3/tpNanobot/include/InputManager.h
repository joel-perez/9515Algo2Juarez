//
// Created by caropistillo
//


#ifndef INPUTMANAGER_H_
#define INPUTMANAGER_H_

#include "SDL2/SDL.h"
#include "InputTable.h"

class InputManager {
public:
	static InputManager* getInstance();
	void update();
	bool isKeyDown(int key);
	bool isKeyUp(int key);
	bool isKeyPressed(KeyboardKey key);
	bool isHoldingKey(int key);
	bool quitRequested();

	InputManager();

private:
	static InputManager* instance;
	const uint8_t* keyboard;
	bool quit;

	uint8_t keyStatus[KEYBOARD_SIZE];
	uint8_t keyHold[KEYBOARD_SIZE];
};

#endif /* INPUTMANAGER_H_ */
