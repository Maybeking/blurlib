#ifndef _BLSYSTEM_H
#define _BLSYSTEM_H
#pragma once

typedef void(*Bl_Function)(void *);

void *bl_store(void *, unsigned int);

void dummy_f(void*);

#endif // _BLSYSTEM_H