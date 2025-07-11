/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:09:58 by ailbezer          #+#    #+#             */
/*   Updated: 2025/07/10 20:57:13 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

void		init_textures(t_cube *cube);
uint32_t	get_tex_color(int index, mlx_texture_t *tex);
static void	tex_pixel_to_image(t_cube *cube, int x);
static void	draw_texture(t_cube *cube, int x, int y, int tex_x);
void		draw_3dmap(t_cube *cube, int x);

void	init_textures(t_cube *cube)
{
	cube->textures = malloc(sizeof(t_textures));
	if (!cube->textures)
		error_msg(INVALID_MALLOC, BRIGHT_RED, DEBUG_FLAG, 1);
	cube->textures->north = mlx_load_png(cube->file->no_path);
	if (!cube->textures->north)
		error_msg(FAILED_LOAD_PNG, BRIGHT_RED, DEBUG_FLAG, 1);
	cube->textures->south = mlx_load_png(cube->file->so_path);
	if (!cube->textures->south)
		error_msg(FAILED_LOAD_PNG, BRIGHT_RED, DEBUG_FLAG, 1);
	cube->textures->east = mlx_load_png(cube->file->ea_path);
	if (!cube->textures->east)
		error_msg(FAILED_LOAD_PNG, BRIGHT_RED, DEBUG_FLAG, 1);
	cube->textures->west = mlx_load_png(cube->file->we_path);
	if (!cube->textures->west)
		error_msg(FAILED_LOAD_PNG, BRIGHT_RED, DEBUG_FLAG, 1);
	cube->textures->door = mlx_load_png("./textures/ghost.png");
	if (!cube->textures->door)
		error_msg(FAILED_LOAD_PNG, BRIGHT_RED, DEBUG_FLAG, 1);
}

uint32_t	get_tex_color(int index, mlx_texture_t *tex)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;

	r = tex->pixels[index + 0];
	g = tex->pixels[index + 1];
	b = tex->pixels[index + 2];
	a = tex->pixels[index + 3];
	// if (a == 0)
		// return ;
	return ((a << 24) | (r << 16) | (g << 8) | b);
}

static void	draw_texture(t_cube *cube, int x, int y, int tex_x)
{
	uint32_t	color;
	int			tex_y;
	int			index;

	tex_y = ((y - cube->dda->draw_start) * cube->textures->tex->height)
		/ (cube->dda->draw_end - cube->dda->draw_start);
	index = (tex_y * cube->textures->tex->width + tex_x) * 4;
	color = get_tex_color(index, cube->textures->tex);
	mlx_put_pixel(cube->principal_map, x, y, color);
}

static void	tex_pixel_to_image(t_cube *cube, int x)
{
	int	tex_x;
	int	y;

	tex_x = (int)(cube->ray->wall_x * cube->textures->tex->width);
	if ((cube->ray->side == 0 && cube->ray->dir_x > 0)
		|| (cube->ray->side == 1 && cube->ray->dir_y < 0))
		tex_x = cube->textures->tex->width - tex_x - 1;
	y = -1;
	while (++y < WIN_HEIGHT)
	{
		if (y < cube->dda->draw_start)
			mlx_put_pixel(cube->principal_map, x, y, cube->file->ceiling);
		else if (y >= cube->dda->draw_start && y < cube->dda->draw_end)
			draw_texture(cube, x, y, tex_x);
		else
			mlx_put_pixel(cube->principal_map, x, y, cube->file->floor);
	}
}

void	draw_3dmap(t_cube *cube, int x)
{
	if (cube->door)
		cube->textures->tex = cube->textures->door;
	else
	{
		if (cube->ray->side == 0)
		{
			if (cube->ray->dir_x > 0)
				cube->textures->tex = cube->textures->west;
			else
				cube->textures->tex = cube->textures->east;
		}
		else
		{
			if (cube->ray->dir_y > 0)
				cube->textures->tex = cube->textures->south;
			else
				cube->textures->tex = cube->textures->north;
		}
	}
	tex_pixel_to_image(cube, x);
}
