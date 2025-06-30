/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:31:36 by ailbezer          #+#    #+#             */
/*   Updated: 2025/06/30 16:51:08 by ailbezer         ###   ########.fr       */
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
		player->dir_y = 1;
		if (dir == 'S')
			player->dir_y = -1;
	}
	else if (dir == 'E' || dir == 'W')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		if (dir == 'W')
			player->dir_x = -1;
	}
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
	player->map_pos_x = *j;
	player->map_pos_y = i;
	set_player_dir(player, dir);
	return (player);
}
