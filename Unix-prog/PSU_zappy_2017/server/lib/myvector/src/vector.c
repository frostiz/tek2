/*
** EPITECH PROJECT, 2018
** myvector
** File description:
** vector
*/

#include "myvector.h"

void vector_init(t_vector *v)
{
	v->capacity = VECTOR_INIT_CAPACITY;
	v->total = 0;
	v->items = malloc(sizeof(void *) * v->capacity);
}

void vector_add(t_vector *v, void *item)
{
	if (v->capacity == v->total)
		vector_resize(v, v->capacity * 2);
	v->items[v->total++] = item;
}

void vector_set(t_vector *v, int index, void *item)
{
	if (index >= 0 && index < v->total)
		v->items[index] = item;
}

void *vector_get(t_vector *v, int index)
{
	if (index >= 0 && index < v->total)
		return v->items[index];
	return NULL;
}

void vector_delete(t_vector *v, int index)
{
	if (index < 0 || index >= v->total)
		return;
	v->items[index] = NULL;
	for (int i = index; i < v->total - 1; i++) {
		v->items[i] = v->items[i + 1];
		v->items[i + 1] = NULL;
	}
	v->total--;
	if (v->total > 0 && v->total == v->capacity / 4)
		vector_resize(v, v->capacity / 2);
}