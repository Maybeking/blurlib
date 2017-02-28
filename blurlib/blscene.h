#ifndef __BLSCENE_H
#define __BLSCENE_H
#pragma once

#include "bllist.h"

#define MAX_ENTITIES 100

typedef void(Bl_Event_Scene)(struct Bl_Scene *);

typedef struct Bl_Scene
{
	char *id;

	void *data;

	List *entities;

	Bl_Event_Scene *on_init;
	Bl_Event_Scene *on_load;
	Bl_Event_Scene *on_update;
	Bl_Event_Scene *on_exit;
} Scene;

// Setup a new Scene
struct Bl_Scene *bl_create_scene(char *);

void bl_scene_update(struct Bl_Scene *);

// Free space from the scene
void bl_destroy_scene(struct Bl_Scene *);

#endif // !__BLSCENE_H

