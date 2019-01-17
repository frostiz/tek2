/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** Timer Manager
*/

#include <unistd.h>
#include <sys/select.h>
#include <sys/timerfd.h>
#include <time.h>
#include <string.h>
#include <stdint.h>
#include "timer_manager.h"


void	timer_manager_init(t_timer_manager *this)
{
	if (!this)
		return;
	vector_init(&this->timers);
	this->start = &timer_manager_start;
	this->stop = &timer_manager_stop;
	this->process = &timer_manager_process;
	printf("initialized timer manager\n");
}

int	timer_manager_start(t_timer_manager *this, long long ms)
{
	t_timer			*timer;
	int			timerfd;
	struct itimerspec	timspec;

	timerfd = timerfd_create(CLOCK_MONOTONIC, 0);
	bzero(&timspec, sizeof(timspec));
	timspec.it_interval.tv_sec = (int)ms / 1000;
	timspec.it_interval.tv_nsec = ((int)ms % 1000) * 1000000;
	timspec.it_value.tv_sec = (int)ms / 1000;
	timspec.it_value.tv_nsec = ((int)ms % 1000) * 1000000;
	int res = timerfd_settime(timerfd, 0, &timspec, 0);
	if (res < 0) {
		perror("timerfd_settime:");
		return (-1);
	}
	timer = malloc(sizeof(t_timer));
	timer->fd = timerfd;
	timer->ms = ms;
	vector_add(&this->timers, timer);
	return (timerfd);
}

void	timer_manager_stop(t_timer_manager *this, int fd)
{
	t_timer	*current;

	for (int i = 0; i < vector_total(&this->timers); i++) {
		current = (t_timer *)(vector_get(&this->timers, i));
		if (current->fd == fd) {
			printf("finished timer execution, deleted.\n");
			close(current->fd);
			vector_delete(&this->timers, i);
			free(current);
			return;
		}
	}
}

void	timer_manager_process(t_timer_manager *this, fd_set read_fds)
{
	int		valread;
	t_timer		*timer;
	uint64_t 	exp;

	for (int i = 0; i < vector_total(&this->timers); i++) {
		timer = (t_timer*)vector_get(&this->timers, i);
		if (FD_ISSET(timer->fd, &read_fds)) {
			valread = read(timer->fd, &exp, sizeof(uint64_t));
			if (valread == sizeof(uint64_t))
				this->stop(this, timer->fd);
			break;
		}
	}
}