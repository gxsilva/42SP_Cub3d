/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_down.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:41:22 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/09 18:40:42 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	set_up_down(void *param);

void	set_up_down(void *param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	if (cube->keys.w)
	{
		if (DEBUG_FLAG)
			print_color("W key pressed", BRIGHT_YELLOW);
		if (wall_collision_player(cube, 'W'))
			return ;
		cube->player->pos_x += calc_pst(cube->player->rot_angle, 0);
		cube->player->pos_y += calc_pst(cube->player->rot_angle, -1);
	}
	else if (cube->keys.s)
	{
		if (DEBUG_FLAG)
			print_color("S key pressed", BRIGHT_YELLOW);
		if (wall_collision_player(cube, 'S'))
			return ;
		cube->player->pos_x -= calc_pst(cube->player->rot_angle, 0);
		cube->player->pos_y -= calc_pst(cube->player->rot_angle, 1);
	}
}
