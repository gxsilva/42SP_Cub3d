/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:57:51 by ailbezer          #+#    #+#             */
/*   Updated: 2025/07/04 14:34:27 by ailbezer         ###   ########.fr       */
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

// void	draw_rays_on_minimap(t_cube *cube)
// {
// 	t_ray ray;
// 	t_dda *ddad;
// 	uint32_t px;
// 	uint32_t py;
// 	int x = -1;

// 	while (++x < WIN_WIDTH)
// 	{
// 		define_ray_dir(&ray, cube->player, x);
// 		ddad = dda(&ray, cube->player, cube->map->matrix);
// 		px = ray.map_x * TILE + TILE / 2;
// 		py = ray.map_y * TILE + TILE / 2;
// 		if (px >= 0 && py >= 0 && px < cube->minimap->width && py < cube->minimap->height)
// 			mlx_put_pixel(cube->minimap, px, py, RED_PX);
// 		// free(ddad);
// 	}
// }

void	draw_rays_on_minimap(t_cube *cube)
{
	t_ray	ray;
	t_dda	*ddad;
	t_player *player = cube->player;
	int		x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		define_ray_dir(&ray, player, x);
		ddad = dda(&ray, player, cube->map->matrix);

		// Calcular a distância perpendicular do jogador até a parede
		double perp_wall_dist;
		if (ray.side == 0)
			perp_wall_dist = ddad->side_dist_x - ray.deltadist_x;
		else
			perp_wall_dist = ddad->side_dist_y - ray.deltadist_y;
		// if (ray.side == 0)
 	    //    perp_wall_dist = (ray.map_x - player->pos_x + (1 - ddad->step_x) / 2) / ray.dir_x;
		// else
		// 	perp_wall_dist = (ray.map_y - player->pos_y + (1 - ddad->step_y) / 2) / ray.dir_y;
		// if (perp_wall_dist < 0)
		// 	perp_wall_dist = 0.0001;

		// Calcular ponto real de colisão do raio
		double hit_x = player->pos_x + ray.dir_x * perp_wall_dist;
		double hit_y = player->pos_y + ray.dir_y * perp_wall_dist;

		// Desenhar linha no minimapa do jogador até o ponto de colisão
		int steps = 30;
		for (int i = 0; i <= steps; i++)
		{
			double t = (double)i / steps;
			uint32_t px = (int)((player->pos_x + t * (hit_x - player->pos_x)) * TILE);
			uint32_t py = (int)((player->pos_y + t * (hit_y - player->pos_y)) * TILE);

			// Segurança: evitar escrever fora da imagem
			if (px >= 0 && px < cube->minimap->width && py >= 0 && py < cube->minimap->height)
				mlx_put_pixel(cube->minimap, px, py, 0xFF0000FF); // azul
		}
		x += 10;
		free(ddad);
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
	player_x = cube->player->pos_x;
	player_y = cube->player->pos_y;
	while (++y < cube->map->height)
	{
		x = -1;
		while (++x < cube->map->width)
		{
			color = get_pixel_color(cube->map, y, x);
			pixel_to_img(cube->minimap, color, y, x);
		}
	}
	pixel_to_img(cube->minimap, RED_PX, player_y, player_x);
}
