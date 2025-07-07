/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 20:03:27 by ailbezer          #+#    #+#             */
/*   Updated: 2025/07/07 14:53:37 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

t_dda	*init_dda(t_ray *ray, double pos_x, double pos_y);
t_dda	*dda(t_ray *ray, t_player *player, int **matrix);
void	calc_wall_dist(t_dda *dda, t_ray *ray);
void	calc_wall_height(t_dda *dda);

// side_dist = distancia inicial ate a primeira linha no eixo x/y 
// step = direção para onde o raio vai ter que andar
t_dda	*init_dda(t_ray *ray, double pos_x, double pos_y)
{
	t_dda	*dda;

	dda = malloc(sizeof(t_dda));
	// ! erro no malloc
	if (ray->dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist_x = (ray->map_x + 1.0 - pos_x) * ray->deltadist_x;
	}
	if (ray->dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist_y = (ray->map_y + 1.0 - pos_y) * ray->deltadist_y;
	}
	return (dda);
}

t_dda	*dda(t_ray *ray, t_player *player, int **matrix)
{
	t_dda	*dda;
	int		hit;

	dda = init_dda(ray, player->pos_x, player->pos_y);
	hit = 0;
	while (hit == 0)
	{
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += ray->deltadist_x;
			ray->map_x += dda->step_x;
			ray->side = 0 ;
		}
		else
		{
			dda->side_dist_y += ray->deltadist_y;
			ray->map_y += dda->step_y;
			ray->side = 1;
		}
		if (matrix[ray->map_y][ray->map_x] > 0)
			hit = 1;
	}
	return (dda);
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

void	calc_wall_dist(t_dda *dda, t_ray *ray)
{
	double	perp_wall_dist;
	
	if (ray->side == 0)
		perp_wall_dist = (dda->side_dist_x - ray->deltadist_x);
	else
		perp_wall_dist = (dda->side_dist_y - ray->deltadist_y);
	if (perp_wall_dist < 0)
			perp_wall_dist = 0.1;
	dda->line_height = (int)(WIN_HEIGHT / perp_wall_dist);
}
