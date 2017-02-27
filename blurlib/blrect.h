#ifndef _BLRECT_H
#define _BLRECT_H
#pragma once

#include <SDL.h>

#include "blpoint.h"

SDL_Rect *bl_create_rect(int, int, int, int);

SDL_Rect bl_create_rect_auto(int, int, int, int);

SDL_Rect *bl_create_rect_from_point(SDL_Point, SDL_Point);

SDL_Rect bl_create_rect_from_point_auto(SDL_Point, SDL_Point);

SDL_Point bl_rect_position(SDL_Rect *);

SDL_Point bl_rect_size(SDL_Rect *);


float bl_rect_right(SDL_Rect *);

float bl_rect_left(SDL_Rect *);

float bl_rect_top(SDL_Rect *);

float bl_rect_down(SDL_Rect *);


Pointf bl_rect_top_right(SDL_Rect *);

Pointf bl_rect_top_left(SDL_Rect *);

Pointf bl_rect_bottom_right(SDL_Rect *);

Pointf bl_rect_bottom_left(SDL_Rect *);


Pointf bl_rect_middle_right(SDL_Rect *);

Pointf bl_rect_middle_left(SDL_Rect *);

Pointf bl_rect_middle_top(SDL_Rect *);

Pointf bl_rect_middle_bottom(SDL_Rect *);


Pointf bl_rect_center(SDL_Rect *);


SDL_Rect bl_rect_add(SDL_Rect *, SDL_Rect *);

SDL_Rect bl_rect_minus(SDL_Rect *, SDL_Rect *);

SDL_Rect bl_rect_product(SDL_Rect *, SDL_Rect *);

SDL_Rect bl_rect_divide(SDL_Rect *, SDL_Rect *);

#endif // !_BLRECT_H
