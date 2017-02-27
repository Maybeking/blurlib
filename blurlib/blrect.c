#include "blrect.h"
#include "blsystem.h"

SDL_Rect *bl_create_rect(int x, int y, int w, int h)
{
	return bl_store(&(SDL_Rect)	{ x, y, w, h }, sizeof(SDL_Rect));
}

SDL_Rect *bl_create_rect_from_point(SDL_Point position, SDL_Point size)
{
	return bl_store(&(SDL_Rect) { position.x, position.y, size.x, size.y }, sizeof(SDL_Rect));
}

SDL_Rect bl_create_rect_auto(int x, int y, int w, int h)
{
	return (SDL_Rect) { x, y, w, h };
}

SDL_Rect bl_create_rect_from_point_auto(SDL_Point position, SDL_Point size)
{
	return (SDL_Rect) { position.x, position.y, size.x, size.y };
}

SDL_Point bl_rect_position(SDL_Rect *rect)
{
	if (rect == NULL)
		return bl_create_point_auto(0, 0);
	return (SDL_Point)
	{
		rect->x,
		rect->y
	};
}

SDL_Point bl_rect_size(SDL_Rect *rect)
{
	if (rect == NULL)
		return bl_create_point_auto(0, 0);
	return (SDL_Point)
	{
		rect->w,
		rect->h
	};
}


float bl_rect_right(SDL_Rect *rect)
{
	return (float) (rect->x + rect->w);
}

float bl_rect_left(SDL_Rect *rect)
{
	return (float) rect->x;
}

float bl_rect_top(SDL_Rect *rect)
{
	return (float) rect->y;
}

float bl_rect_down(SDL_Rect *rect)
{
	return (float) (rect->y + rect->h);
}


Pointf bl_rect_top_right(SDL_Rect *rect)
{
	return (Pointf)
	{
		(float) (rect->x + rect->w),
		(float) rect->y
	};
}

Pointf bl_rect_top_left(SDL_Rect *rect)
{
	return (Pointf)
	{
		(float) rect->x,
		(float) rect->y
	};
}

Pointf bl_rect_bottom_right(SDL_Rect *rect)
{
	return (Pointf)
	{
		(float) (rect->x + rect->w),
		(float) (rect->y + rect->h)
	};
}

Pointf bl_rect_bottom_left(SDL_Rect *rect)
{
	return (Pointf)
	{
		(float) rect->x,
		(float) (rect->y + rect->h)
	};
}


Pointf bl_rect_middle_right(SDL_Rect *rect)
{
	return (Pointf)
	{
		(float) (rect->x + rect->w),
		(float) rect->y + (float) rect->h / 2.0F
	};
}

Pointf bl_rect_middle_left(SDL_Rect *rect)
{
	return (Pointf)
	{
		(float) rect->x,
		(float) rect->y
	};
}

Pointf bl_rect_middle_top(SDL_Rect *rect)
{
	return (Pointf)
	{
		(float) rect->x + (float) rect->w / 2.0F,
		(float) rect->y
	};
}

Pointf bl_rect_middle_bottom(SDL_Rect *rect)
{
	return (Pointf)
	{
		(float) rect->x + (float) rect->w / 2.0F,
		(float) (rect->y + rect->h)
	};
}


Pointf bl_rect_center(SDL_Rect *rect)
{
	return (Pointf)
	{
		(float) rect->x + (float) rect->w / 2.0F,
		(float) rect->y + (float) rect->h / 2.0F
	};
}


SDL_Rect bl_rect_add(SDL_Rect *rect1, SDL_Rect *rect2)
{
	return (SDL_Rect)
	{
		rect1->x + rect2->x,
		rect1->y + rect2->y,
		rect1->w + rect2->w,
		rect1->h + rect2->h
	};
}

SDL_Rect bl_rect_minus(SDL_Rect *rect1, SDL_Rect *rect2)
{
	return (SDL_Rect)
	{
		rect1->x - rect2->x,
		rect1->y - rect2->y,
		rect1->w - rect2->w,
		rect1->h - rect2->h
	};
}

SDL_Rect bl_rect_product(SDL_Rect *rect1, SDL_Rect *rect2)
{
	return (SDL_Rect)
	{
		rect1->x * rect2->x,
		rect1->y * rect2->y,
		rect1->w * rect2->w,
		rect1->h * rect2->h
	};
}

SDL_Rect bl_rect_divide(SDL_Rect *rect1, SDL_Rect *rect2)
{
	return (SDL_Rect)
	{
		rect1->x / rect2->x,
		rect1->y / rect2->y,
		rect1->w / rect2->w,
		rect1->h / rect2->h
	};
}