/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_key_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:50:37 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/04 20:23:29 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

double	calc_pst(double rot_angle, int opt)
{
	if (opt == 0)
		return ((cos(rot_angle) * PLAYER_SPEED));
	else
		return ((sin(rot_angle) * PLAYER_SPEED));
}


// !WIP
int	wall_colision_player(t_cube *cube, int dirX, int dirY)
{
	int		**matrix;
	int		pos_x;
	int		pos_y;
	(void)dirX;
	matrix = cube->map->matrix;
	pos_x = (int)cube->player->pos.x + calc_pst(0, 0) * PLAYER_SPEED;
	pos_y = (int)cube->player->pos.y + (dirY * PLAYER_SPEED);
	if (matrix[pos_y][pos_x] == 1)
		return (1);
	return (0);
}
