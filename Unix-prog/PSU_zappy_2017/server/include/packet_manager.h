/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** PacketManager
*/

#ifndef PACKET_MANAGER_H_
# define PACKET_MANAGER_H_

#include "client.h"
#include "mystring.h"
#include "myvector.h"
#include "packet/packet_parser.h"

#define FORWARD "Forward|7"
#define RIGHT "Right|7"
#define LEFT "Left|7"
#define INVENTORY "Inventory|1"
#define LOOK "Look|7"
#define CONNECT_NBR "Connect_nbr|0"
#define TAKE "Take|7"
#define SET "Set|7"
#define INCANTATION "Incantation|300"
#define BROADCAST "Broadcast|7"
#define MSZ "msz"
#define BCT "bct"
#define MCT "mct"
#define TNA "tna"
#define PPO "ppo"
#define PLV "plv"
#define PIN "pin"
#define SGT "sgt"
#define SST "sst"
#define GRAPHIC "graphic"

typedef void handler(t_client *client, t_zappy_packet packet);

typedef struct		s_packet_info
{
	char		*header;
	int		time_unit;
}			t_packet_info;

void		parse_packet(t_client *client, const char *data);
void		process_packet(t_client *client, t_zappy_packet packet);
int		get_packet_id(char *header);
int		get_packet_size(char **splitted);
void		destroy_packet(t_zappy_packet packet);
t_packet_info	*get_header_info(char *header);
t_packet_info	*get_packet_info_by_header(char *header);

void 	rpl_handshake(t_client *client);
void 	rpl_welcome(t_client *client);
void	rpl_msz(t_client *client, int broadcast);
void	rpl_bct(t_client *client, int x, int y, int broadcast);
void 	rpl_tna(t_client *client, char *team_name, int broadcast);
void 	rpl_pnw(t_client *client, t_client *target, int broadcast);
void	rpl_ppo(t_client *client, int uid, int broadcast);
void	rpl_plv(t_client *client, int uid, int broadcast);
void	rpl_pin(t_client *client, int uid, int broadcast);
void	rpl_pex(t_client *client, int uid);
void	rpl_pbc(t_client *client, int uid, char *broadcast);
void	rpl_pic(t_client *client, t_vector uid);
void	rpl_pie(t_client *client, int uid);
void	rpl_pfk(t_client *client, int uid);
void	rpl_pdr(t_client *client, int uid, int resource);
void	rpl_pgt(t_client *client, int uid, int resource);
void	rpl_pdi(t_client *client, int uid);
void	rpl_enw(t_client *client, int egg_uid, int uid);
void	rpl_eht(t_client *client, int egg_uid);
void	rpl_ebo(t_client *client, int egg_uid);
void	rpl_edi(t_client *client, int egg_uid);
void	rpl_sgt(t_client *client, int broadcast);
void	rpl_sst(t_client *client, long int frequency, int broadcast);
void	rpl_seg(t_client *client, char *team);
void	rpl_smg(t_client *client, char *message);
void	rpl_suc(t_client *client);
void	rpl_sbp(t_client *client);
void	rpl_look_up(t_client *client);
void	rpl_look_down(t_client *client);
void	rpl_look_left(t_client *client);
void	rpl_look_right(t_client *client);
void	rpl_dead(t_client *client);

void	handshake_command(t_client *client, t_zappy_packet packet);
void	msz_command(t_client *client, t_zappy_packet packet);
void	bct_command(t_client *client, t_zappy_packet packet);
void	mct_command(t_client *client, t_zappy_packet packet);
void	tna_command(t_client *client, t_zappy_packet packet);
void	forward_command(t_client *client, t_zappy_packet packet);
void	ppo_command(t_client *client, t_zappy_packet packet);
void	plv_command(t_client *client, t_zappy_packet packet);
void	pin_command(t_client *client, t_zappy_packet packet);
void	sgt_command(t_client *client, t_zappy_packet packet);
void	sst_command(t_client *client, t_zappy_packet packet);
void	graphic_command(t_client *client, t_zappy_packet packet);
void	right_command(t_client *client, t_zappy_packet packet);
void	left_command(t_client *client, t_zappy_packet packet);
void	inventory_command(t_client *client, t_zappy_packet packet);
void	look_command(t_client *client, t_zappy_packet packet);
void	connect_nbr_command(t_client *client, t_zappy_packet packet);
void	take_command(t_client *client, t_zappy_packet packet);
void	set_command(t_client *client, t_zappy_packet packet);
void	incantation_command(t_client *client, t_zappy_packet packet);

void	incantation_first_call(t_client *client);
void	broadcast_command(t_client *client, t_zappy_packet packet);

#endif /* PACKET_MANAGER_H_ */