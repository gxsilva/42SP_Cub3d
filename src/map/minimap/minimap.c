/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:57:51 by ailbezer          #+#    #+#             */
/*   Updated: 2025/07/03 19:18:22 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

static uint32_t	get_pixel_color(t_map *map, int y, int x);
static void		pixel_to_img(mlx_image_t *img, uint32_t color, int y, int x);
void			draw_minimap(t_cube *cube);

static uint32_t	get_pixel_color(t_map *map, int y, int x)
{
	if (map->matrix[y][x] == 0)
		return (WHITE_PX);
	else if (map->matrix[y][x] == 1)
		return (GRAY_PX);
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
	int			player_x;
	int			player_y;

	y = -1;
	color = BLACK_PX;
	player_x = cube->player->pos.x;
	player_y = cube->player->pos.y;
	while (++y < cube->map->height)
	{
		x = -1;
		while (++x < cube->map->width)
		{
			color = get_pixel_color(cube->map, y, x);
			pixel_to_img(cube->minimap, color, y, x);
		}
	}
	pixel_to_img(cube->minimap, ORANGE_PX, player_y, player_x);
}
