/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   principal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 19:14:07 by ailbezer          #+#    #+#             */
/*   Updated: 2025/07/07 14:53:46 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

void	draw_3dmap(t_dda *dda, int x, mlx_image_t *map);
void	define_ray_dir(t_ray *ray, t_player *player, int x);
void	raycast(void *param);

void	define_ray_dir(t_ray *ray, t_player *player, int x)
{
	ray->camera_x = 2 * x / (double)WIN_WIDTH -1;
	ray->dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->deltadist_x = fabs(1 / ray->dir_x);
	ray->deltadist_y = fabs(1 / ray->dir_y);
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
}

void	draw_3dmap(t_dda *dda, int x, mlx_image_t *map)
{
	int y;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		if (y < dda->draw_start)
			mlx_put_pixel(map, x, y, BLUE_PX);
		else if (y >= dda->draw_start && y < dda->draw_end)
			mlx_put_pixel(map, x, y, RED_PX);
		else
			mlx_put_pixel(map, x, y, GREEN_PX);
	}
}

void	raycast(void *param)
{
	t_cube	*cube = (t_cube *)param;
	t_ray *ray;
	int x;
	t_dda *ddad;

	ray = malloc(sizeof(t_ray));
	// !erro no malloc
	x = -1;
	while (++x < WIN_WIDTH)
	{
		define_ray_dir(ray, cube->player, x);
		ddad = dda(ray, cube->player, cube->map->matrix);
		calc_wall_dist(ddad, ray);
		calc_wall_height(ddad);
		draw_3dmap(ddad, x, cube->principal_map);
		free(ddad);
	}
	free(ray);
}