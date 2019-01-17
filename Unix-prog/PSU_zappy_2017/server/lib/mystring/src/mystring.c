/*
** EPITECH PROJECT, 2018
** myString
** File description:
** myString
*/

#include "mystring.h"

static void	init_pointer(t_string *this)
{
	this->assign_s = &assign_s;
	this->assign_c = &assign_c;
	this->append_s = &append_s;
	this->append_c = &append_c;
	this->at = &at;
	this->clear = &clear;
	this->size = &size;
	this->compare_s = &compare_s;
	this->compare_c = &compare_c;
	this->copy = &copy;
	this->c_str = &c_str;
	this->empty = &empty;
}

void	string_init(t_string *this, const char *s)
{
	if (this == NULL)
		return;
	if (s != NULL)
		this->str = strdup(s);
	init_pointer(this);
	this->find_s = &find_s;
	this->find_c = &find_c;
	this->insert_c = &insert_c;
	this->insert_s = &insert_s;
	this->to_int = &to_int;
	this->split_s = &split_s;
	this->split_c = &split_c;
	this->aff = &aff;
	this->join_c = &join_c;
	this->join_s = &join_s;
}

void	string_destroy(t_string *this)
{
	if (this == NULL)
		return;
	if (this->str != NULL)
		free(this->str);
	this->str = NULL;
}