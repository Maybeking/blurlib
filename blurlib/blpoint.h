#ifndef _BLPOINT_H
#define _BLPOINT_H
#pragma once

#include <SDL.h>

typedef struct Bl_Pointui
{
	unsigned int x;
	unsigned int y;
} Pointui;

typedef struct Bl_Pointf
{
	float x;
	float y;
} Pointf;

SDL_Point *bl_create_point(int x, int y);

SDL_Point bl_create_point_auto(int x, int y);

struct Bl_Pointf *bl_create_pointf(float x, float y);

struct Bl_Pointf bl_create_pointf_auto(float x, float y);

struct Bl_Pointui *bl_create_pointui(unsigned int x, unsigned int y);

struct Bl_Pointui bl_create_pointui_auto(unsigned int x, unsigned int y);


SDL_Point bl_point_ftoi(struct Bl_Pointf);

struct Bl_Pointf bl_point_itof(SDL_Point);


struct SDL_Point bl_point_add(struct SDL_Point, struct SDL_Point);

struct SDL_Point bl_point_minus(struct SDL_Point, struct SDL_Point);

struct SDL_Point bl_point_product(struct SDL_Point, struct SDL_Point);

struct SDL_Point bl_point_divide(struct SDL_Point, struct SDL_Point);



struct Bl_Pointui bl_pointui_add(struct Bl_Pointui, struct Bl_Pointui);

struct Bl_Pointui bl_pointui_minus(struct Bl_Pointui, struct Bl_Pointui);

struct Bl_Pointui bl_pointui_product(struct Bl_Pointui, struct Bl_Pointui);

struct Bl_Pointui bl_pointui_divide(struct Bl_Pointui, struct Bl_Pointui);



struct Bl_Pointf bl_pointf_add(struct Bl_Pointf, struct Bl_Pointf);

struct Bl_Pointf bl_pointf_minus(struct Bl_Pointf, struct Bl_Pointf);

struct Bl_Pointf bl_pointf_product(struct Bl_Pointf, struct Bl_Pointf);

struct Bl_Pointf bl_pointf_divide(struct Bl_Pointf, struct Bl_Pointf);

#endif // !_BLVECTOR2_H
