/*
** EPITECH PROJECT, 2018
** mystring
** File description:
** mystring lib
*/

#include "mystring.h"

size_t	copy(t_string *this, char *s, size_t n, size_t pos)
{
	size_t len;
	size_t i = pos;
	size_t j = 0;

	if (this == NULL || this->str == NULL || n == 0)
		return (0);
	len = strlen(this->str);
	if (pos > len)
		return (0);
	while (this->str[i] != '\0' && j < n)
	{
		s[j] = this->str[i];
		i++;
		j++;
	}
	s[j] = '\0';
	return (j);
}

const char	*c_str(t_string *this)
{
	return (this->str);
}

void	aff(t_string *this)
{
	if (this == NULL || this->str == NULL)
		return;
	printf("%s", this->str);
}