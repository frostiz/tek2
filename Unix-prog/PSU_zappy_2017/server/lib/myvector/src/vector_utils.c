/*
** EPITECH PROJECT, 2018
** myvector
** File description:
** vector utils
*/

#include "myvector.h"

int vector_total(t_vector *v)
{
	return v->total;
}

void vector_resize(t_vector *v, int capacity)
{
	void **items = realloc(v->items, sizeof(void *) * capacity);

	if (items) {
		v->items = items;
		v->capacity = capacity;
	}
}

void vector_free(t_vector *v)
{
	free(v->items);
}