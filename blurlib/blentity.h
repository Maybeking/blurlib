#ifndef _BLENTITY_H
#define _BLENTITY_H
#pragma once

#include <SDL.h>
#include "blscene.h"

typedef void (Bl_Event_Entity)(struct Bl_Entity *);

typedef struct Bl_Entity
{
	char *id;

	void *user_data;

	int z;

	Scene *scene;

	int enabled;

	SDL_Rect *transform;

	SDL_Texture *texture;
	SDL_Rect *texture_clip;
	SDL_Point *texture_translate;
	
	Bl_Event_Entity* on_added;
	Bl_Event_Entity* on_update;
	Bl_Event_Entity* on_remove;


} Entity;

struct Bl_Entity *bl_create_entity(char *, Scene *, void *, Bl_Event_Entity *);

struct Bl_Entity *bl_create_entity_r(char *, Scene *, void *, Bl_Event_Entity *, SDL_Rect *);

struct Bl_Entity *bl_create_entity_tt(char *, Scene *, void *, Bl_Event_Entity *, SDL_Rect *, SDL_Texture *, SDL_Rect *, SDL_Point *);

SDL_Point bl_entity_position(struct Bl_Entity*);

SDL_Rect *bl_entity_display_texture_rect(struct Bl_Entity *);

void bl_destroy_entity(struct Bl_Entity*);

int bl_scene_add_entity(struct Bl_Scene *, Entity *);

#endif // !_BLENTITY_H
