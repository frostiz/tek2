/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** Timer Manager
*/

#ifndef TIMER_MANAGER_H_
# define TIMER_MANAGER_H_

#include "myvector.h"


typedef struct		s_timer
{
	int		fd;
	long long	ms;
}			t_timer;


typedef struct		s_timer_manager
{
	t_vector	timers;
	int		(*start)(struct s_timer_manager *this, long long ms);
	void		(*stop)(struct s_timer_manager *this, int fd);
	void		(*process)(struct s_timer_manager *this,
					fd_set read_fds);
}			t_timer_manager;

void			timer_manager_init(t_timer_manager *this);
int			timer_manager_start(t_timer_manager *this,
							long long ms);
void			timer_manager_stop(t_timer_manager *this, int fd);
void			timer_manager_process(t_timer_manager *this,
							fd_set read_fds);

#endif /* TIMER_MANAGER_H_ */