/*
** EPITECH PROJECT, 2018
** myString
** File description:
** myString
*/

#ifndef ASTRING_H_
#define ASTRING_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct		s_string
{
	char		*str;
	void		(*assign_s)(struct s_string *this,
					const struct s_string *str);
	void		(*assign_c)(struct s_string *this, const char *s);
	void		(*append_s)(struct s_string *this,
					const struct s_string *ap);
	void		(*append_c)(struct s_string *this, const char *ap);
	char		(*at)(struct s_string *this, size_t pos);
	void		(*clear)(struct s_string *this);
	int		(*size)(struct s_string *this);
	int		(*compare_s)(struct s_string *this,
					const struct s_string *str);
	int		(*compare_c)(struct s_string *this, const char *str);
	size_t		(*copy)(struct s_string *this, char *s,
					size_t n, size_t pos);
	const char	*(*c_str)(struct s_string *this);
	int		(*empty)(struct s_string *this);
	int		(*find_s)(struct s_string *this,
					const struct s_string *str, size_t pos);
	int		(*find_c)(struct s_string *this,
					const char *str, size_t pos);
	void		(*insert_c)(struct s_string *this,
					size_t pos, const char *str);
	void		(*insert_s)(struct s_string *this, size_t pos,
					const struct s_string *str);
	int		(*to_int)(struct s_string *this);
	struct s_string	*(*split_s)(struct s_string *this,
				char separator);
	char		**(*split_c)(struct s_string *this, char separator);
	void		(*aff)(struct s_string *this);
	void		(*join_c)(struct s_string *this, char delim,
					const char **tab);
	void		(*join_s)(struct s_string *this, char delim,
					struct s_string *tab);
}			t_string;

void		string_init(t_string *this, const char *s);
void		string_destroy(t_string *this);

void		assign_s(t_string *this, const t_string *str);
void		assign_c(t_string *this, const char *s);
void		append_s(t_string *this, const t_string *ap);
void		append_c(t_string *this, const char *ap);
char		at(t_string *this, size_t pos);
void		clear(t_string *this);
int		size(t_string *this);
int		compare_s(t_string *this, const t_string *str);
int		compare_c(t_string *this, const char *str);
size_t		copy(t_string *this, char *s, size_t n, size_t pos);
const char	*c_str(t_string *this);
int		empty(t_string *this);
int		find_s(t_string *this, const t_string *str, size_t pos);
int		find_c(t_string *this, const char *str, size_t pos);
void		insert_c(t_string *this, size_t pos, const char *str);
void		insert_s(t_string *this, size_t pos, const t_string *str);
int		to_int(t_string *this);
t_string	*split_s(t_string *this, char separator);
char		**split_c(t_string *this, char separator);
void		aff(t_string *this);
void		join_c(t_string *this, char delim, const char **tab);
void		join_s(t_string *this, char delim, t_string *tab);

#endif /* ASTRING_H_ */