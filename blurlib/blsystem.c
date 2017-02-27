#include <SDL.h>

#include "blsystem.h"

void *bl_store(void *data, unsigned int size)
{
	return SDL_memcpy(SDL_malloc(size), data, size);
}

void dummy_f(void *data)
{

}