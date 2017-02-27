#include <SDL_image.h>
#include <stdio.h>

#include "blcore.h"
#include "blentity.h"
#include "blrect.h"


struct Bl_Core *bl_create_app(char *app_name, int width, int height)
{
	return bl_create_core(app_name, width, height);
}

struct Bl_Core *bl_create_core(char *app_name, int width, int height)
{
	_bl_app.app_name = app_name;
	_bl_app.scene = &_scene;


	// Init video display
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		// Create window 
		_bl_app.window = SDL_CreateWindow(app_name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
		_bl_app.screen = SDL_CreateRenderer(_bl_app.window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (_bl_app.window == NULL || _bl_app.screen == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			SDL_SetRenderDrawColor(_bl_app.screen, 0, 0, 0, 0xFF);

			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags)) 
			{ 
				printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
			}
		}
	}

	_bl_app.done = 0;

	return &_bl_app;
}


int bl_core_set_scene(Scene *scene)
{
	_next_scene = scene;
	return 1;
}


void bl_core_run(int fps)
{
	SDL_Event event;

	while (!_bl_app.done)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				_bl_app.done = 1;
			}
		}


		bl_core_update();

		bl_core_draw();

		SDL_Delay(fps);
	}

	bl_core_exit();
}

static void bl_core_update()
{
	if ((_bl_app.on_update) != NULL)
		(_bl_app.on_update)(&_bl_app);

	if (_scene != NULL && _scene == _next_scene)
	{
		bl_scene_update(_scene);
		_scene->on_update(_scene);
	}
	else if (_next_scene != NULL)
	{
		if (_scene != NULL)
		{
			_scene->on_exit(_scene);
			bl_destroy_scene(_scene);
		}

		_scene = _next_scene;

		_scene->on_init(_scene);
		_scene->on_load(_scene);
	}
	else
		printf("No scene declared . . .");
}

static void bl_core_draw()
{
	SDL_RenderClear(_bl_app.screen);


	if (_scene == NULL)
		return;


	bl_list_foreach_data(_scene->entities, &bl_core_render_entity);

	SDL_RenderPresent(_bl_app.screen);
}

int bl_core_render_entity(List *list, Entity* entity)
{
	return SDL_RenderCopy(_bl_app.screen, entity->texture, entity->texture_clip, bl_entity_display_texture_rect(entity));
}

static void bl_core_exit()
{
	if (_bl_app.on_quit != NULL)
		(_bl_app.on_quit)(&_bl_app);

	if (_scene != NULL)
	{
		_scene->on_exit(_scene);
		bl_destroy_scene(_scene);
	}

	SDL_DestroyRenderer(_bl_app.screen);
	_bl_app.screen = NULL;

	SDL_DestroyWindow(_bl_app.window);
	_bl_app.window = NULL;

	IMG_Quit();
	SDL_Quit();

}

SDL_Surface* bl_load_surface(char *path)
{

	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path);
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError());
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface(loadedSurface, SDL_GetWindowSurface(_bl_app.window)->format, NULL);
		if (optimizedSurface == NULL)
		{
			printf("Unable to optimize image %s! SDL Error: %s\n", path, SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return optimizedSurface;
}

SDL_Texture* bl_load_texture(char *path)
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path);
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(_bl_app.screen, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}