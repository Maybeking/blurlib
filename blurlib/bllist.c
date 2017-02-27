#include <stdlib.h>

#include <SDL.h>

#include "bllist.h"
#include "blentity.h"

struct Bl_List *bl_create_list(unsigned int size, Bl_Function *free)
{
	struct Bl_List* temp = SDL_malloc(sizeof(List));

	temp->total_nodes = 0;

	temp->free = free;

	temp->first = SDL_malloc(sizeof(Node));
	temp->first->data = NULL;
	temp->first->child = NULL;
	temp->first->parent = NULL;
	temp->first->id = 0;

	temp->last = temp->first;

	return temp;
}

static int bl_list_remove_node(struct Bl_List *list, struct Bl_Node *node)
{
	if (list->free != NULL)
		(*list->free)(node->data);
	if (node->parent != NULL)
		node->parent->child = node->child;
	if (node->child != NULL)
		node->child->parent = node->parent;
	list->total_nodes--;
	SDL_free(node);
	return 1;
}

int bl_list_append(struct Bl_List *list, void *data)
{
	struct Bl_Node *temp = SDL_malloc(sizeof(Node));
	if (temp == NULL)
		return 0;
	temp->data = data;
	temp->child = NULL;
	temp->parent = list->last;
	list->last->child = temp;
	list->total_nodes++;
	temp->id = list->total_nodes;
	list->last = temp;

	return 1;
}

int bl_list_remove(struct Bl_List *list, void *data)
{
	struct Bl_Node *node = list->first;
	while (node != NULL)
	{
		if (node->data == data)
		{
			struct Bl_Node *node_temp = node;
			node = node->child;
			bl_list_remove(list, node_temp);
			return 1;
		}
		else
			node = node->child;
	}
	return 0;
}

int bl_list_remove_by_id(struct Bl_List *list, unsigned int id)
{
	struct Bl_Node *node = list->first;
	while (node != NULL)
	{
		if (node->id == id)
		{
			struct Bl_Node *node_temp = node;
			node = node->child;
			bl_list_remove(list, node_temp);
			return 1;
		}
		else
			node = node->child;
	}
	return 0;
}

void *bl_list_foreach_data(struct Bl_List *list, Bl_Find_Function find)
{
	struct Bl_Node *node = list->first;
	while (node != NULL)
	{
		if (find != NULL && node->data != NULL && (find)(list, node->data))
		{
			return node->data;
		}
		else
			node = node->child;
	}
	return NULL;
}

void *bl_list_foreach_node(struct Bl_List *list, Bl_Find_Function find)
{
	struct Bl_Node *node = list->first;
	while (node != NULL)
	{
		if (*find != NULL && (find)(list, node))
		{
			return node;
		}
		else
			node = node->child;
	}
	return NULL;
}

void *bl_list_find_data_by_id(struct Bl_List *list, unsigned int id)
{
	struct Bl_Node *node = list->first;
	while (node != NULL)
	{
		if (node->id == id)
		{
			return node->data;
		}
		else
			node = node->child;
	}
	return NULL;
}

void bl_destroy_list(struct Bl_List *list)
{
	bl_list_foreach_node(list, &bl_list_remove_node);
}