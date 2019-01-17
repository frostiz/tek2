/*
** EPITECH PROJECT, 2018
** mystring
** File description:
** mystring lib
*/

#include "mystring.h"

void	insert_c(t_string *this, size_t pos, const char *str)
{
	char	*tmp;
	char	*old_str;

	if (this == NULL || str == NULL)
		return;
	if (pos > strlen(this->str))
		return (this->append_c(this, str));
	tmp = malloc(strlen(this->str) + strlen(str) + 1);
	if (tmp == NULL)
		return;
	this->copy(this, tmp, pos, 0);
	old_str = strdup(this->str);
	free(this->str);
	this->str = tmp;
	this->append_c(this, str);
	this->append_c(this, &old_str[pos]);
	free(old_str);
}

void	insert_s(t_string *this, size_t pos, const t_string *str)
{
	this->insert_c(this, pos, str->str);
}