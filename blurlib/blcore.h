#ifndef _BLCORE_H
#define _BLCORE_H
#pragma once

#include <SDL.h>
#include "blscene.h"
#include "bllist.h"
#include "blentity.h"

// Setup the window and other settings
struct Bl_Core *bl_create_app(char *, int, int);

struct Bl_Core *bl_create_core(char *, int, int);

// Add a scene
int bl_core_set_scene(Scene *);

// Launch the game to the first scene
void bl_core_run(int);

// Update components
static void bl_core_update();

// Draw components
static void bl_core_draw();

int bl_core_render_entity(List *, Entity *);

// Force exit the app and called on exit
void bl_core_exit();

// Optimized loading surface
SDL_Surface *bl_load_surface(char *);

// Optimized loading texture
SDL_Texture *bl_load_texture(char *);

typedef void(*Bl_Event_Core)(struct Bl_Core *);

typedef struct Bl_Core
{
	int done;

	char *app_name;
	
	SDL_Window *window;
	SDL_Renderer *screen;

	Scene **scene;

	Bl_Event_Core on_init;
	Bl_Event_Core on_quit;
	Bl_Event_Core on_update;
} App;


// The root of the the app
static struct Bl_Core _bl_app;

// Current running scene
static Scene *_scene;

// Next scene to be blit
static Scene *_next_scene;


#endif // !_BLCORE_H
