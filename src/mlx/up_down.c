/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_down.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:41:22 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/05 16:10:51 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	set_up_down(mlx_key_data_t keydata, void *param);

void	set_up_down(mlx_key_data_t keydata, void *param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
	{
		if (DEBUG_FLAG)
			print_color("W key pressed", BRIGHT_YELLOW);
		if (wall_collision_player(cube, 'W'))
			return ;
		cube->player->pos.x += calc_pst(cube->player->rot_angle, 0);
		cube->player->pos.y += calc_pst(cube->player->rot_angle, -1);
	}
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
	{
		if (DEBUG_FLAG)
			print_color("S key pressed", BRIGHT_YELLOW);
		if (wall_collision_player(cube, 'S'))
			return ;
		cube->player->pos.x -= calc_pst(cube->player->rot_angle, 0);
		cube->player->pos.y -= calc_pst(cube->player->rot_angle, 1);
	}
}
