#include <SDL.h>
#include "blevent.h"
#include "blsystem.h"

void bl_update_event()
{
	SDL_PumpEvents();
	currentKeyState = SDL_GetKeyboardState(NULL);
	SDL_memcpy(lastKeyState, currentKeyState, SDL_NUM_SCANCODES);
}

int bl_event_is_key_pressed(SDL_Scancode key)
{
	return currentKeyState[key];
}

int bl_event_are_keys_pressed(SDL_Scancode *key)
{
	int to_return = 1;

	while (key != NULL)
	{
		to_return = to_return && currentKeyState[*key];
		if (!to_return)
			return 0;
		key++;
	}
	return 1;
}

