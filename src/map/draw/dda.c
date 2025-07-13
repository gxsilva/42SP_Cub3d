/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 20:03:27 by ailbezer          #+#    #+#             */
/*   Updated: 2025/07/13 19:34:51 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

void	calc_wall_height(t_dda *dda);
void	init_dda(t_cube *cube, t_ray *ray, double pos_x, double pos_y);
void	check_hit(t_cube *cube, int *hit);

void	init_dda(t_cube *cube, t_ray *ray, double pos_x, double pos_y)
{
	cube->dda = malloc(sizeof(t_dda));
	if (!cube->dda)
		error_msg(INVALID_MALLOC, BRIGHT_RED, DEBUG_FLAG, 1);
	if (ray->dir_x < 0)
	{
		cube->dda->step_x = -1;
		cube->dda->side_dist_x = (pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		cube->dda->step_x = 1;
		cube->dda->side_dist_x = (ray->map_x + 1.0 - pos_x) * ray->deltadist_x;
	}
	if (ray->dir_y < 0)
	{
		cube->dda->step_y = -1;
		cube->dda->side_dist_y = (pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		cube->dda->step_y = 1;
		cube->dda->side_dist_y = (ray->map_y + 1.0 - pos_y) * ray->deltadist_y;
	}
}

void	check_hit(t_cube *cube, int *hit)
{
	t_ray	*ray;
	int		**matrix;

	ray = cube->ray;
	matrix = cube->map->matrix;
	if (matrix[ray->map_y][ray->map_x] > 0
		&& matrix[ray->map_y][ray->map_x] < 3)
		*hit = 1;
}

void	perform_dda(t_cube *cube, void (*check_hit)(t_cube *cube, int *hit))
{
	int		hit;

	init_dda(cube, cube->ray, cube->player->pos_x, cube->player->pos_y);
	hit = 0;
	while (hit == 0 && (cube->ray->map_x >= 0
			&& cube->ray->map_x < cube->map->width
			&& cube->ray->map_y >= 0 && cube->ray->map_y < cube->map->height))
	{
		if (cube->dda->side_dist_x < cube->dda->side_dist_y)
		{
			cube->dda->side_dist_x += cube->ray->deltadist_x;
			cube->ray->map_x += cube->dda->step_x;
			cube->ray->side = 0 ;
		}
		else
		{
			cube->dda->side_dist_y += cube->ray->deltadist_y;
			cube->ray->map_y += cube->dda->step_y;
			cube->ray->side = 1;
		}
		check_hit(cube, &hit);
	}
}

void	calc_wall_height(t_dda *dda)
{
	dda->draw_start = (WIN_HEIGHT - dda->line_height) / 2;
	dda->draw_end = (WIN_HEIGHT + dda->line_height) / 2;
	if (dda->draw_start < 0)
		dda->draw_start = 0;
	if (dda->draw_end >= WIN_HEIGHT)
		dda->draw_end = WIN_HEIGHT - 1;
}

void	calc_wall_dist(t_dda *dda, t_ray *ray, t_player *player)
{
	t_cube	*cube;

	cube = get_cube();
	if (ray->side == 0)
	{
		cube->ray->perp_wall_dist = (dda->side_dist_x - ray->deltadist_x);
		ray->wall_x = player->pos_y + cube->ray->perp_wall_dist * ray->dir_y;
	}
	else
	{
		cube->ray->perp_wall_dist = (dda->side_dist_y - ray->deltadist_y);
		ray->wall_x = player->pos_x + cube->ray->perp_wall_dist * ray->dir_x;
	}
	ray->wall_x -= floor(ray->wall_x);
	dda->line_height = (int)(WIN_HEIGHT / cube->ray->perp_wall_dist);
}
