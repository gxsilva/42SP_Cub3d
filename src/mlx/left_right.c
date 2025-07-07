/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:41:22 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/05 18:24:21 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	set_left_right(mlx_key_data_t keydata, void *param);

void	set_left_right(mlx_key_data_t keydata, void *param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
	{
		if (DEBUG_FLAG)
			print_color("D key pressed", BRIGHT_YELLOW);
		if (wall_collision_player(cube, 'D'))
			return ;
		cube->player->pos_x -= calc_pst(cube->player->rot_angle, 1);
		cube->player->pos_y += calc_pst(cube->player->rot_angle, 0);
	}
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
	{
		if (DEBUG_FLAG)
			print_color("A key pressed", BRIGHT_YELLOW);
		if (wall_collision_player(cube, 'A'))
			return ;
		cube->player->pos_x += calc_pst(cube->player->rot_angle, -1);
		cube->player->pos_y -= calc_pst(cube->player->rot_angle, 0);
	}
}
