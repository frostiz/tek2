/*
** EPITECH PROJECT, 2018
** mystring
** File description:
** mystring lib
*/

#include "mystring.h"

void	assign_s(t_string *this, const t_string *str)
{
	if (this == NULL || str == NULL)
		return;
	if (this->str != NULL)
		free(this->str);
	if (str->str != NULL)
		this->str = strdup(str->str);
}

void	assign_c(t_string *this, const char *s)
{
	if (this == NULL)
		return;
	if (this->str != NULL)
		free(this->str);
	if (s != NULL)
		this->str = strdup(s);
}

void	append_s(t_string *this, const t_string *ap)
{
	char	*tmp = NULL;
	size_t	str_size = 1;

	if (this == NULL || ap == NULL || ap->str == NULL)
		return;
	if (this->str != NULL) {
		str_size += strlen(this->str);
		tmp = strdup(this->str);
		free(this->str);
	}
	str_size += strlen(ap->str);
	this->str = malloc(str_size);
	if (this->str == NULL)
		return;
	this->str[0] = '\0';
	if (tmp != NULL) {
		strcat(this->str, tmp);
		free(tmp);
	}
	strcat(this->str, ap->str);
}

void	append_c(t_string *this, const char *ap)
{
	char	*tmp = NULL;
	size_t	str_size = 1;

	if (this == NULL || ap == NULL)
		return;
	if (this->str != NULL) {
		str_size += strlen(this->str);
		tmp = strdup(this->str);
		free(this->str);
	}
	str_size += strlen(ap);
	this->str = malloc(str_size);
	if (this->str == NULL)
		return;
	this->str[0] = '\0';
	if (tmp != NULL) {
		strcat(this->str, tmp);
		free(tmp);
	}
	strcat(this->str, ap);
}
