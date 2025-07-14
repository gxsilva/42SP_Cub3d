/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_doors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:32:20 by ailbezer          #+#    #+#             */
/*   Updated: 2025/07/14 18:50:48 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

void	render_doors(void *param);
void	check_door_hit(t_cube *cube, int *hit);

void	render_doors(void *param)
{
	t_cube	*cube;
	int		x;

	cube = (t_cube *)param;
	cube->ray = malloc(sizeof(t_ray));
	if (!cube->ray)
		error_msg(INVALID_MALLOC, BRIGHT_RED, DEBUG_FLAG, 1);
	x = -1;
	while (++x < WIN_WIDTH)
	{
		define_ray_dir(cube->ray, cube->player, x);
		perform_dda(cube, &check_door_hit);
		calc_wall_dist(cube->dda, cube->ray, cube->player);
		calc_wall_height(cube->dda);
		draw_doors(cube, x);
		free(cube->dda);
		cube->dda = NULL;
	}
	free(cube->ray);
	cube->ray = NULL;
}

void	check_door_hit(t_cube *cube, int *hit)
{
	cube->door = false;
	if (cube->ray->map_x >= 0 && cube->ray->map_x < cube->map->width
		&& cube->ray->map_y >= 0 && cube->ray->map_y < cube->map->height)
	{
		if (cube->map->matrix[cube->ray->map_y][cube->ray->map_x] == 3)
		{
			cube->door = true;
			*hit = 1;
		}
	}
}

