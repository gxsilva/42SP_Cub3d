/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:09:58 by ailbezer          #+#    #+#             */
/*   Updated: 2025/07/11 19:03:38 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

void		init_textures(t_cube *cube);
uint32_t	get_tex_color(int index, mlx_texture_t *tex);
void		tex_pixel_to_image(t_cube *cube, int x);
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

static int	calc_tex_x(t_cube *cube)
{
	int		tex_x;

	tex_x = (int)(cube->ray->wall_x * cube->textures->tex->width);
	if ((cube->ray->side == 0 && cube->ray->dir_x > 0)
		|| (cube->ray->side == 1 && cube->ray->dir_y < 0))
		tex_x = cube->textures->tex->width - tex_x - 1;
	return (tex_x);
}

static uint32_t	get_color(t_textures *textures, int tex_x, int tex_y)
{
	int			index;

	if (tex_y < 0)
		tex_y = 0;
	if (tex_y >= (int)textures->tex->height)
		tex_y = textures->tex->height - 1;
	index = (tex_y * textures->tex->width + tex_x) * 4;
	return (get_tex_color(index, textures->tex));
}

static void	draw_tex_line(t_cube *cube, int x, int tex_x)
{
	float		step;
	float		tex_pos;
	int			y;
	int			tex_y;
	uint32_t	color;

	step = (float)cube->textures->tex->height / (float)cube->dda->line_height;
	tex_pos = (cube->dda->draw_start - WIN_HEIGHT
			/ 2 + cube->dda->line_height / 2) * step;
	y = cube->dda->draw_start - 1;
	while (++y < cube->dda->draw_end)
	{
		tex_y = (int)tex_pos;
		color = get_color(cube->textures, tex_x, tex_y);
		mlx_put_pixel(cube->principal_map, x, y, color);
		tex_pos += step;
	}
}

void	tex_pixel_to_image(t_cube *cube, int x)
{
	int	tex_x;
	int	y;

	tex_x = calc_tex_x(cube);
	y = -1;
	while (++y < WIN_HEIGHT)
	{
		if (y < cube->dda->draw_start)
			mlx_put_pixel(cube->principal_map, x, y, cube->file->ceiling);
		else if (y < cube->dda->draw_end)
			break ;
		else
			mlx_put_pixel(cube->principal_map, x, y, cube->file->floor);
	}
	draw_tex_line(cube, x, tex_x);
	y = cube->dda->draw_end - 1;
	while (++y < WIN_HEIGHT)
		mlx_put_pixel(cube->principal_map, x, y, cube->file->floor);
}
