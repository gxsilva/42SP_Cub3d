/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 21:32:19 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/14 03:31:29 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	check_sprite_hit(t_cube *cube, int *hit)
{
	cube->sprite = false;
	if (cube->ray->map_x >= 0 && cube->ray->map_x < cube->map->width
		&& cube->ray->map_y >= 0 && cube->ray->map_y < cube->map->height)
	{
		if (cube->map->matrix[cube->ray->map_y][cube->ray->map_x] == 5)
		{
			cube->sprite = true;
			*hit = 1;
		}
	}
}

void	draw_sprites(t_cube *cube, int x)
{
	int	tex_x;
	int	y;

	if (cube->ray->perp_wall_dist > cube->z_buffer[x] || !cube->sprite)
		return ;
	cube->textures->tex =  cube->sprites->frames[cube->sprites->crr_frame];
	tex_x = get_tex_x(cube);
	y = -1;
	while (++y < WIN_HEIGHT)
		draw_texture(cube, x, y, tex_x);
}

void	render_sprite(void *param)
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
		perform_dda(cube, &check_sprite_hit);
		calc_wall_dist(cube->dda, cube->ray, cube->player);
		calc_wall_height(cube->dda);
		draw_sprites(cube, x);
		free(cube->dda);
		cube->dda = NULL;
	}
	free(cube->ray);
	cube->ray = NULL;
}