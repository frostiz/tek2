/*
** EPITECH PROJECT, 2018
** mystring
** File description:
** mystring lib
*/

#include "mystring.h"

static int	count_separator(char *str, char separator)
{
	int	j = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == separator)
			j++;
	}
	return (j);
}

t_string	*split_s(t_string *this, char separator)
{
	char		**tmp;
	t_string	*result;
	int		i = 0;

	if (this == NULL || this->str == NULL)
		return (NULL);
	tmp = this->split_c(this, separator);
	while (tmp[i])
		i++;
	result = malloc(sizeof(t_string) * (i + 1) + 1);
	string_init(&result[i], "");
	while (i > 0) {
		i--;
		string_init(&result[i], tmp[i]);
	}
	return (result);
}

char	**split_c(t_string *this, char separator)
{
	const char	delim[2] = {separator, '\0'};
	char		**result;
	char		*tmp;
	char		*old_str = NULL;
	int		j = 0;

	if (this == NULL || this->str == NULL)
		return (NULL);
	j = count_separator(this->str, separator);
	result = malloc(sizeof(char *) * (j + 2));
	old_str = strdup(this->str);
	tmp = strtok(old_str, delim);
	j = 0;
	while (tmp != NULL) {
		result[j] = strdup(tmp);
		tmp = strtok(NULL, delim);
		j++;
	}
	result[j] = NULL;
	return (result);
}