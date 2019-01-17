/*
** EPITECH PROJECT, 2018
** mystring
** File description:
** mystring lib
*/

#include "mystring.h"

char	at(t_string *this, size_t pos)
{
	if (this == NULL || this->str == NULL || pos > strlen(this->str))
		return (-1);
	return (this->str[pos]);
}

void	clear(t_string *this)
{
	if (this == NULL)
		return;
	if (this->str != NULL) {
		free(this->str);
		this->str = malloc(1);
		this->str[0] = '\0';
	}
}

int	size(t_string *this)
{
	size_t	len;

	if (this == NULL || this->str == NULL)
		return (-1);
	len = strlen(this->str);
	return (len);
}

int	empty(t_string *this)
{
	if (this == NULL || this->str == NULL || strlen(this->str) == 0)
		return (1);
	return (-1);
}

int	to_int(t_string *this)
{
	int	result;

	if (this == NULL || this->str == NULL)
		return (0);
	result = atoi(this->str);
	return (result);
}