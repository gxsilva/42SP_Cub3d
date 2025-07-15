/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elapsed_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:42:08 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/14 20:02:13 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	track_elapsed_time(void *param);

void	change_sprite_pst(t_cube *cube)
{
	int		new_x;
	int		new_y;

	new_x = ft_random(0, cube->map->width) % cube->map->width;
	new_y = ft_random(0, cube->map->height) % cube->map->height;
	while (cube->map->matrix[new_y][new_x] != 0)
	{
		new_x = ft_random(0, cube->map->width) % cube->map->width;
		new_y = ft_random(0, cube->map->height) % cube->map->height;
	}
	cube->map->matrix[cube->sprites->y][cube->sprites->x] = 0;
	cube->sprites->x = new_x;
	cube->sprites->y = new_y;
	cube->map->matrix[cube->sprites->y][cube->sprites->x] = 5;
}

void	sprite_refresh(t_cube *cube, double elapsed)
{
	cube->sprites->refresh_time += elapsed;
	if (cube->sprites->refresh_time >= SPRITE_REFRESH)
	{
		cube->sprites->refresh_time = 0;
		change_sprite_pst(cube);
	}
}

void	track_elapsed_time(void *param)
{
	t_cube	*cube;
	double	current_t;

	cube = (t_cube *)param;
	current_t = mlx_get_time();
	cube->elapsed_t = current_t - cube->last_t;
	cube->last_t = current_t;
	if (BONUS)
	{
		update_sprites(cube);
		sprite_refresh(cube, cube->elapsed_t);
	}
}
