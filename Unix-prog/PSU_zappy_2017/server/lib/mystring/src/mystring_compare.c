/*
** EPITECH PROJECT, 2018
** mystring
** File description:
** mystring lib
*/

#include "mystring.h"

int	compare_s(t_string *this, const t_string *str)
{
	int	result;

	if (this == NULL || str == NULL || this->str == NULL ||
		str->str == NULL)
		return (-1);
	result = strcmp(this->str, str->str);
	return (result);
}

int	compare_c(t_string *this, const char *str)
{
	int	result;

	if (this == NULL || str == NULL || this->str == NULL || str == NULL)
		return (-1);
	result = strcmp(this->str, str);
	return (result);
}

int	find_s(t_string *this, const t_string *str, size_t pos)
{
	char	*result;
	int	find_pos;

	if (this == NULL || this->str == NULL)
		return (-1);
	if (pos > strlen(this->str))
		return (-1);
	result = strstr(&this->str[pos], str->str);
	if (result == NULL)
		return (-1);
	find_pos = result - &this->str[pos];
	return (find_pos + pos);
}

int	find_c(t_string *this, const char *str, size_t pos)
{
	char	*result;
	int	find_pos;

	if (this == NULL || this->str == NULL)
		return (-1);
	if (pos > strlen(this->str))
		return (-1);
	result = strstr(&this->str[pos], str);
	if (result == NULL)
		return (-1);
	find_pos = result - &this->str[pos];
	return (find_pos + pos);
}