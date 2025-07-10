/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 20:03:27 by ailbezer          #+#    #+#             */
/*   Updated: 2025/07/10 18:13:09 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

void	init_dda(t_cube *cube, t_ray *ray, double pos_x, double pos_y);
void	perform_dda(t_cube *cube, t_ray *ray, t_player *player, int **matrix);
void	calc_wall_dist(t_dda *dda, t_ray *ray, t_player *player);
void	calc_wall_height(t_dda *dda);

// side_dist = distancia inicial ate a primeira linha no eixo x/y 
// step = direção para onde o raio vai ter que andar
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

void	perform_dda(t_cube *cube, t_ray *ray, t_player *player, int **matrix)
{
	int		hit;

	init_dda(cube, ray, player->pos_x, player->pos_y);
	hit = 0;
	while (hit == 0)
	{
		if (cube->dda->side_dist_x < cube->dda->side_dist_y)
		{
			cube->dda->side_dist_x += ray->deltadist_x;
			ray->map_x += cube->dda->step_x;
			ray->side = 0 ;
		}
		else
		{
			cube->dda->side_dist_y += ray->deltadist_y;
			ray->map_y += cube->dda->step_y;
			ray->side = 1;
		}
		if (matrix[ray->map_y][ray->map_x] > 0)
			hit = 1;
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
	double	perp_wall_dist;

	if (ray->side == 0)
	{
		perp_wall_dist = (dda->side_dist_x - ray->deltadist_x);
		ray->wall_x = player->pos_y + perp_wall_dist * ray->dir_y;
	}
	else
	{
		perp_wall_dist = (dda->side_dist_y - ray->deltadist_y);
		ray->wall_x = player->pos_x + perp_wall_dist * ray->dir_x;
	}
	ray->wall_x -= floor(ray->wall_x);
	dda->line_height = (int)(WIN_HEIGHT / perp_wall_dist);
}
