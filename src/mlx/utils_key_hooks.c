/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_key_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:50:37 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/07 15:09:40 by lsilva-x         ###   ########.fr       */
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

static void	wall_colission_node(t_vec *pos, t_vec offset, char direction)
{
	if (direction == 'D')
	{
		pos->x = (int)(get_cube()->player->pos_x - offset.y);
		pos->y = (int)(get_cube()->player->pos_y + offset.x);
	}
	else if (direction == 'A')
	{
		pos->x = (int)(get_cube()->player->pos_x + offset.y);
		pos->y = (int)(get_cube()->player->pos_y - offset.x);
	}
}

int	wall_collision_player(t_cube *cube, int direction)
{
	int		**matrix;
	t_vec	pos;
	t_vec	offset;

	matrix = cube->map->matrix;
	offset.x = calc_pst(cube->player->rot_angle, 0);
	offset.y = calc_pst(cube->player->rot_angle, 1);
	if (direction == 'W')
	{
		pos.x = (int)(cube->player->pos_x + offset.x);
		pos.y = (int)(cube->player->pos_y + offset.y);
	}
	else if (direction == 'S')
	{
		pos.x = (int)(cube->player->pos_x - offset.x);
		pos.y = (int)(cube->player->pos_y - offset.y);
	}
	wall_colission_node(&pos, offset, direction);
	if (matrix[(int)pos.y][(int)pos.x] == 1)
		return (1);
	return (0);
}
