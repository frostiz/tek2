/*
** EPITECH PROJECT, 2018
** mystring
** File description:
** mystring lib
*/

#include "mystring.h"

void	join_c(t_string *this, char delim, const char **tab)
{
	int	i = 0;
	int	len = 0;
	char	separator[2] = {delim, '\0'};

	while (tab[i] != NULL) {
		len += strlen(tab[i]);
		i++;
	}
	this->str = malloc(sizeof(char) * (len + i + 1));
	i = 0;
	while (tab[i + 1] != NULL) {
		this->append_c(this, tab[i]);
		this->append_c(this, separator);
		i++;
	}
	this->append_c(this, tab[i]);
}

void	join_s(t_string *this, char delim, t_string *tab)
{
	int	i = 0;
	int	len = 0;
	char	separator[2] = {delim, '\0'};

	while (tab[i].str != NULL) {
		len += strlen(tab[i].str);
		i++;
	}
	this->str = malloc(sizeof(char) * (len + i + 1));
	i = 0;
	while (tab[i + 1].str != NULL) {
		this->append_c(this, tab[i].str);
		this->append_c(this, separator);
		i++;
	}
	this->append_c(this, tab[i].str);
}