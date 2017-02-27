#include <SDL.h>
#include <stdlib.h>

#include "blpoint.h"
#include "blsystem.h"

SDL_Point *bl_create_point(int x, int y)
{
	return bl_store(&(SDL_Point) { x, y }, sizeof(SDL_Point));
}

SDL_Point bl_create_point_auto(int x, int y)
{
	return (SDL_Point) { x, y };
}

struct Bl_Pointf *bl_create_pointf(float x, float y)
{
	return bl_store(&(Pointf) { x, y }, sizeof(Pointf));
}

struct Bl_Pointf bl_create_pointf_auto(float x, float y)
{
	return (struct Bl_Pointf) { x, y };
}

struct Bl_Pointui *bl_create_pointui(unsigned int x, unsigned int y)
{
	return bl_store(&(Pointui) { x, y }, sizeof(struct Bl_Pointui));
}

struct Bl_Pointui bl_create_pointui_auto(unsigned int x, unsigned int y)
{
	return (struct Bl_Pointui) { x, y };
}



SDL_Point bl_point_ftoi(struct Bl_Pointf pointf)
{
	return (SDL_Point)
	{
		(int) pointf.x,
		(int) pointf.y
	};
}

struct Bl_Pointf bl_point_itof(SDL_Point point)
{
	return (Pointf)
	{
		(float) point.x,
		(float) point.y
	};
}



struct SDL_Point bl_point_add(struct SDL_Point point1, struct SDL_Point point2)
{
	return (SDL_Point)
	{ 
		point1.x + point2.x, 
		point1.y + point2.y 
	};
}

struct SDL_Point bl_point_minus(struct SDL_Point point1, struct SDL_Point point2)
{
	return (SDL_Point)
	{
		point1.x - point2.x,
		point1.y - point2.y
	};
}

struct SDL_Point bl_point_product(struct SDL_Point point1, struct SDL_Point point2)
{
	return (SDL_Point)
	{
		point1.x  * point2.x,
		point1.y  * point2.y
	};
}

struct SDL_Point bl_point_divide(struct SDL_Point point1, struct SDL_Point point2)
{
	return (SDL_Point)
	{
		point1.x / point2.x,
		point1.y / point2.y
	};
}



struct Bl_Pointui bl_pointui_add(struct Bl_Pointui point1, struct Bl_Pointui point2)
{
	return (Pointui)
	{
		point1.x + point2.x,
		point1.y + point2.y
	};
}

struct Bl_Pointui bl_pointui_minus(struct Bl_Pointui point1, struct Bl_Pointui point2)
{
	return (Pointui)
	{
		point1.x - point2.x,
		point1.y - point2.y
	};
}

struct Bl_Pointui bl_pointui_product(struct Bl_Pointui point1, struct Bl_Pointui point2)
{
	return (Pointui)
	{
		point1.x * point2.x,
		point1.y * point2.y
	};
}

struct Bl_Pointui bl_pointui_divide(struct Bl_Pointui point1, struct Bl_Pointui point2)
{
	return (Pointui)
	{
		point1.x / point2.x,
		point1.y / point2.y
	};
}



struct Bl_Pointf bl_pointf_add(struct Bl_Pointf point1, struct Bl_Pointf point2)
{
	return (Pointf)
	{
		point1.x + point2.x,
		point1.y + point2.y
	};
}

struct Bl_Pointf bl_pointf_minus(struct Bl_Pointf point1, struct Bl_Pointf point2)
{
	return (Pointf)
	{
		point1.x - point2.x,
		point1.y - point2.y
	};
}

struct Bl_Pointf bl_pointf_product(struct Bl_Pointf point1, struct Bl_Pointf point2)
{
	return (Pointf)
	{
		point1.x * point2.x,
		point1.y * point2.y
	};
}

struct Bl_Pointf bl_pointf_divide(struct Bl_Pointf point1, struct Bl_Pointf point2)
{
	return (Pointf)
	{
		point1.x / point2.x,
		point1.y / point2.y
	};
}