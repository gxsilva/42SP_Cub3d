/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_doors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:32:20 by ailbezer          #+#    #+#             */
/*   Updated: 2025/07/13 17:39:01 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

void	render_doors(void *param);
void	check_door_hit(t_cube *cube, int *hit);
void	draw_doors(t_cube *cube, int x);

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

void	draw_doors(t_cube *cube, int x)
{
	int	tex_x;
	int	y;

	if (cube->ray->perp_wall_dist > cube->z_buffer[x] || !cube->door)
		return ;
	cube->textures->tex = cube->textures->door;
	tex_x = get_tex_x(cube);
	y = -1;
	while (++y < WIN_HEIGHT)
		draw_texture(cube, x, y, tex_x);
}
