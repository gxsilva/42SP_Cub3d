/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:57:51 by ailbezer          #+#    #+#             */
/*   Updated: 2025/07/14 19:37:41 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

static uint32_t	get_pixel_color(t_map *map, int y, int x);
static void		pixel_to_img(mlx_image_t *img, uint32_t color, int y, int x);
void			draw_minimap(t_cube *cube);
int				wall_colision_minimap(t_cube *cube);
void			render_minimap(void *param);

void	render_minimap(void *param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	memset(cube->minimap->pixels,
		0,
		cube->minimap->height * cube->minimap->width * sizeof(uint32_t));
	draw_minimap(cube);
	draw_player(cube->minimap, cube->player->pos_x, cube->player->pos_y);
}

static uint32_t	get_pixel_color(t_map *map, int y, int x)
{
	if (map->matrix[y][x] == 0)
		return (WHITE_PX);
	else if (map->matrix[y][x] == 1)
		return (GRAY_PX);
	else if (map->matrix[y][x] == 3)
		return (GOLD_PX);
	else if (map->matrix[y][x] == 5)
		return (RED_PX);
	else
		return (GREEN_PX);
}

static void	pixel_to_img(mlx_image_t *img, uint32_t color, int y, int x)
{
	int			i;
	int			j;
	uint32_t	pixel_x;
	uint32_t	pixel_y;

	i = -1;
	while (++i < TILE)
	{
		j = -1;
		while (++j < TILE)
		{
			pixel_x = x * TILE + j;
			pixel_y = y * TILE + i;
			mlx_put_pixel(img, pixel_x, pixel_y, color);
		}
	}
}

void	draw_minimap(t_cube *cube)
{
	int			y;
	int			x;
	uint32_t	color;

	y = -1;
	color = BLACK_PX;
	while (++y < cube->map->height)
	{
		x = -1;
		while (++x < cube->map->width)
		{
			color = get_pixel_color(cube->map, y, x);
			pixel_to_img(cube->minimap, color, y, x);
		}
	}
}

int	wall_colision_minimap(t_cube *cube)
{
	int	center_x;
	int	center_y;
	int	map_x;
	int	map_y;

	center_x = (int)round(cube->player->pos_x * TILE);
	center_y = (int)round(cube->player->pos_y * TILE);
	map_x = center_x / TILE;
	map_y = center_y / TILE;
	if (map_x < 0 || map_x >= cube->map->width
		|| map_y < 0 || map_y >= cube->map->height)
		return (0);
	if (cube->map->matrix[map_y][map_x] > 0)
		return (0);
	return (1);
}
