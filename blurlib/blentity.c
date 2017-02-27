#include <SDL_image.h>

#include "blentity.h"
#include "blscene.h"
#include "blrect.h"
#include "blsystem.h"

struct Bl_Entity *bl_create_entity(unsigned int id, Scene *scene)
{
	struct Bl_Entity *temp_entity = SDL_malloc(sizeof(Entity));

	temp_entity->id = id;
	temp_entity->z = 0;
	temp_entity->enabled = 1;

	temp_entity->transform = bl_create_rect(0, 0, 0, 0);

	temp_entity->on_added =
		temp_entity->on_update =
		temp_entity->on_remove = dummy_f;

	temp_entity->texture = NULL;

	return temp_entity;
}

struct Bl_Entity *bl_create_entity_r(unsigned int id, Scene *scene, SDL_Rect *rect)
{
	struct Bl_Entity *temp_entity = bl_create_entity(id, scene);

	if (rect != NULL)
		temp_entity->transform = rect;

	return temp_entity;
}

struct Bl_Entity *bl_create_entity_tt(unsigned int id, Scene *scene, SDL_Rect *rect, SDL_Texture *texture, SDL_Rect *texture_clip, SDL_Point *texture_translate)
{
	SDL_Texture *t = texture;
	struct Bl_Entity *temp_entity = bl_create_entity_r(id, scene, rect);

	int w, h;

	temp_entity->texture = t;

	if (texture_clip != NULL)
		temp_entity->texture_clip = texture_clip;
	else
	{
		if (SDL_QueryTexture(temp_entity->texture, NULL, NULL, &w, &h) < 0)
			temp_entity->texture_clip = NULL;
		else
			temp_entity->texture_clip = bl_create_rect(0, 0, w, h);
	}

	if (texture_translate != NULL)
		temp_entity->texture_translate = texture_translate;
	else
		temp_entity->texture_translate = bl_create_point(0, 0);

	return temp_entity;
}

SDL_Point bl_entity_position(struct Bl_Entity *entity)
{
	return bl_rect_position(entity->transform);
}

SDL_Rect *bl_entity_display_texture_rect(struct Bl_Entity *entity)
{
	return bl_create_rect_from_point(bl_point_add(bl_entity_position(entity), *entity->texture_translate), bl_rect_size(entity->texture_clip));
}

void bl_destroy_entity(struct Bl_Entity *entity)
{
	SDL_DestroyTexture(entity->texture);
	
	free(entity->transform);
	free(entity->texture_clip);
	SDL_free(entity);
}