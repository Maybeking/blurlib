#ifndef _LIST_H
#define _LIST_H
#pragma once

#include "blsystem.h"

typedef struct Bl_Node
{
	unsigned int id;
	void *data;
	struct Bl_Node *child;
	struct Bl_Node *parent;

} Node;

typedef struct Bl_List
{
	struct Bl_Node *first;
	struct Bl_Node *last;

	unsigned int data_size;
	unsigned int total_nodes;

	Bl_Function *free;

	
} List;

typedef int(*Bl_Find_Function)(struct Bl_List *, void *);

struct Bl_List *bl_create_list(unsigned int, Bl_Function *);

static int bl_list_remove_node(struct Bl_List *, struct Bl_Node*);

int bl_list_append(struct Bl_List *, void *);

int bl_list_remove(struct Bl_List *, void *);

int bl_list_remove_by_id(struct Bl_List *, unsigned int);

void *bl_list_foreach_data(struct Bl_List *, Bl_Find_Function);

void *bl_list_foreach_node(struct Bl_List *, Bl_Find_Function);

void *bl_list_find_data_by_id(struct Bl_List *, unsigned int);

void bl_destroy_list(struct Bl_List*);
 
#endif