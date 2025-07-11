/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:09:58 by ailbezer          #+#    #+#             */
/*   Updated: 2025/07/11 18:11:13 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

void		init_textures(t_cube *cube);
uint32_t	get_tex_color(int index, mlx_texture_t *tex);
static void	tex_pixel_to_image(t_cube *cube, int x);
// static void	draw_texture(t_cube *cube, int x, int y, int tex_x);
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
	return ((a << 24) | (r << 16) | (g << 8) | b);
}

// static void	draw_texture(t_cube *cube, int x, int y, int tex_x)
// {
// 	uint32_t	color;
// 	int			tex_y;
// 	int			index;

// 	tex_y = ((y - cube->dda->draw_start) * cube->textures->tex->height)
// 		/ (cube->dda->draw_end - cube->dda->draw_start);
// 	index = (tex_y * cube->textures->tex->width + tex_x) * 4;
// 	color = get_tex_color(index, cube->textures->tex);
// 	mlx_put_pixel(cube->principal_map, x, y, color);
// }

static void	tex_pixel_to_image(t_cube *cube, int x)
{
	int		tex_x;
	int		y;
	float	step;
	float	tex_pos;
	int		draw_start;
	int		draw_end;
	int		tex_y;
	int		index;
	uint32_t color;

	tex_x = (int)(cube->ray->wall_x * cube->textures->tex->width);
	if ((cube->ray->side == 0 && cube->ray->dir_x > 0)
		|| (cube->ray->side == 1 && cube->ray->dir_y < 0))
		tex_x = cube->textures->tex->width - tex_x - 1;

	step = (float)cube->textures->tex->height / (float)cube->dda->line_height;
	tex_pos = (cube->dda->draw_start - WIN_HEIGHT / 2 + cube->dda->line_height / 2) * step;

	draw_start = cube->dda->draw_start;
	draw_end = cube->dda->draw_end;

	// Draw ceiling
	for (y = 0; y < draw_start; ++y)
		mlx_put_pixel(cube->principal_map, x, y, cube->file->ceiling);

	// Draw wall (texture)
	for (y = draw_start; y < draw_end; ++y)
	{
		tex_y = (int)tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		else if (tex_y >= (int)cube->textures->tex->height)
			tex_y = cube->textures->tex->height - 1;
		index = (tex_y * cube->textures->tex->width + tex_x) * 4;
		color = get_tex_color(index, cube->textures->tex);
		mlx_put_pixel(cube->principal_map, x, y, color);
		tex_pos += step;
	}

	// Draw floor
	for (y = draw_end; y < WIN_HEIGHT; ++y)
		mlx_put_pixel(cube->principal_map, x, y, cube->file->floor);
}

void	draw_3dmap(t_cube *cube, int x)
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
	tex_pixel_to_image(cube, x);
}
