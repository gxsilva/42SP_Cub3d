/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:31:36 by ailbezer          #+#    #+#             */
/*   Updated: 2025/07/09 18:07:50 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

static void	set_player_dir(t_player *player, char dir);
t_player	*init_player(int i, int *j, char dir);

static void	set_player_dir(t_player *player, char dir)
{
	if (dir == 'N' || dir == 'S')
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->rot_angle = 3 * M_PI / 2;
		if (dir == 'S')
		{
			player->rot_angle = M_PI / 2;
			player->dir_y = 1;
		}
	}
	else if (dir == 'E' || dir == 'W')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->rot_angle = 0;
		if (dir == 'W')
		{
			player->rot_angle = M_PI;
			player->dir_x = -1;
		}
	}
}

void	set_player_plane(t_player *player)
{
	player->plane_x = -(player->dir_y) * FOV;
	player->plane_y = player->dir_x * FOV;
}

t_player	*init_player(int i, int *j, char dir)
{
	t_player	*player;

	if ((get_cube())->player)
	{
		free((get_cube())->player);
		(get_cube())->player = NULL;
		return (NULL);
	}
	player = malloc(sizeof(t_player));
	player->pos_x = *j + 0.5;
	player->pos_y = i + 0.5;
	player->pos_x = *j + 0.5;
	player->pos_y = i + 0.5;
	player->move_speed = PLAYER_SPEED;
	player->rot_speed = ROT_SPEED;
	set_player_dir(player, dir);
	set_player_plane(player);
	return (player);
}
