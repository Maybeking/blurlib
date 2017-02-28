#ifndef _BLEVENT_H
#define _BLEVENT_H
#pragma once

#include <SDL.h>
#include "bllist.h"

const Uint8 * currentKeyState;
const Uint8 lastKeyState[SDL_NUM_SCANCODES];


void bl_update_event();

int bl_event_is_key_pressed(SDL_Scancode);

int bl_event_are_keys_pressed(SDL_Scancode *);

int bl_event_is_key_release(SDL_Scancode *);

int bl_event_are_keys_release(SDL_Scancode);

#endif // !_BLEVENT_H
