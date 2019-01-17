/*
** EPITECH PROJECT, 2018
** myvector
** File description:
** myvector
*/

#ifndef MYVECTOR_H_
# define MYVECTOR_H_

#include <stdio.h>
#include <stdlib.h>

#define VECTOR_INIT_CAPACITY 4

typedef struct s_vector
{
	void	**items;
	int	capacity;
	int	total;
}		t_vector;

void	vector_init(t_vector *);
int	vector_total(t_vector *);
void	vector_resize(t_vector *, int);
void	vector_add(t_vector *, void *);
void	vector_set(t_vector *, int, void *);
void	*vector_get(t_vector *, int);
void	vector_delete(t_vector *, int);
void	vector_free(t_vector *);

#endif /* MYVECTOR_H_ */