/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:00:11 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/14 18:51:14 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

void	draw_sky(t_cube *cube, int y, int x);
void	draw_doors(t_cube *cube, int x);
void	draw_3dmap(t_cube *cube, int x);

void	draw_sky(t_cube *cube, int y, int x)
{
	int			tex_x;
	int			tex_y;
	uint32_t	color;
	int			index;
	
	tex_y = (y * cube->textures->sky->height) / cube->dda->draw_start;
	tex_x = (x * cube->textures->sky->width) / WIN_WIDTH;
	index = (tex_y * cube->textures->sky->width + tex_x) * 4;
	color = get_tex_color(index, cube->textures->sky);
	mlx_put_pixel(cube->principal_map, x, y, color);
}

void	draw_doors(t_cube *cube, int x)
{
	int	tex_x;
	int	y;

	if (cube->ray->perp_wall_dist > cube->z_buffer[x] || !cube->door)
		return ;
	cube->textures->tex = cube->textures->door;
	tex_x = get_tex_x(cube);
	y = -1;
	while (++y < WIN_HEIGHT)
		draw_texture(cube, x, y, tex_x);
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
