/*
** EPITECH PROJECT, 2021
** PSU_zappy_2017
** File description:
** Created by Antoine Duez, modified by Brandon Gillis
*/

#include "client.h"
#include "packet_manager.h"
#include "utils.h"

void	client_init_position(t_pos *position, t_map_manager map_manager)
{
	position->x = rand() % (map_manager.width - 1);
	position->y = rand() % (map_manager.height - 1);
	switch (rand() % 3) {
	case 0:
		position->look_to = NORTH;
		break;
	case 1:
		position->look_to = WEST;
		break;
	case 2:
		position->look_to = SOUTH;
		break;
	case 3:
		position->look_to = EAST;
		break;
	}
}

int	find_client_amount_on_cell(t_client *client, int x, int y)
{
	int i = 0;
	int amount = 0;
	t_client *other;

	while (i < vector_total(&client->zappy->clients)) {
		other = vector_get(&client->zappy->clients, i);
		if (other->position.x == x && other->position.y == y)
			++amount;
		++i;
	}
	return (amount);
}

void	client_check_alive(t_client *this)
{
	if (this->is_ai != 1 || this->authenticated == 0)
		return;
	if (current_timestamp() >= this->next_food_timestamp) {
		this->inventory.items.food--;
		if (this->inventory.items.food <= 0) {
			rpl_dead(this);
			rpl_pdi(this, this->uid);
			client_destroy(this);
			return;
		}
		this->food_timer(this);
		printf("remove 1 food\n");
	}
}

void	client_food_timer(t_client *this)
{
	int frequency;
	float time_unit;
	long long ms;

	frequency = this->zappy->startup_info.frequency;
	time_unit = ((float)FOOD_FREQUENCY / (float)frequency) * 1000.f;
	ms = (int)time_unit;
	if (ms <= 0) {
		this->food_timer(this);
		return;
	}
	this->next_food_timestamp = current_timestamp() + (int)ms;
	this->zappy->timer_manager->start(this->zappy->timer_manager, ms);
}