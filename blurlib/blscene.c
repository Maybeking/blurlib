#include <stdlib.h>
#include <SDL.h>

#include "blscene.h"
#include "blentity.h"
#include "bllist.h"
#include "blsystem.h"

struct Bl_Scene *bl_create_scene(char *id)
{
	struct Bl_Scene *temp_scene = SDL_malloc(sizeof(struct Bl_Scene));

	temp_scene->id = id;

	temp_scene->entities = bl_create_list(sizeof(Entity), NULL);

	temp_scene->on_init =
		temp_scene->on_load =
		temp_scene->on_update =
		temp_scene->on_exit = &dummy_f;

	return temp_scene;
}

void bl_scene_update(struct Bl_Scene *scene)
{
	Node *temp = scene->entities->first;
	while (temp != NULL)
	{
		if (temp->data != NULL)
			((Entity*) temp->data)->on_update((Entity*) temp->data);
		temp = temp->child;
	}
}


void bl_destroy_scene(struct Bl_Scene *scene)
{
	bl_destroy_list(scene->entities);
	SDL_free(scene);
}
