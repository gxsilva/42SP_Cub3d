/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:00:11 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/13 18:52:25 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../../includes/header.h"

// void	draw_3dmap(t_cube *cube, int x)
// {
// 	if (cube->ray->side == 0)
// 	{
// 		if (cube->ray->dir_x > 0)
// 			cube->textures->tex = cube->textures->west;
// 		else
// 			cube->textures->tex = cube->textures->east;
// 	}
// 	else
// 	{
// 		if (cube->ray->dir_y > 0)
// 			cube->textures->tex = cube->textures->south;
// 		else
// 			cube->textures->tex = cube->textures->north;
// 	}
// 	tex_pixel_to_image(cube, x);
// }

// uint32_t	get_tex_color(int index, mlx_texture_t *tex)
// {
// 	uint8_t	r;
// 	uint8_t	g;
// 	uint8_t	b;
// 	uint8_t	a;

// 	r = tex->pixels[index + 0];
// 	g = tex->pixels[index + 1];
// 	b = tex->pixels[index + 2];
// 	a = tex->pixels[index + 3];
// 	return ((a << 24) | (r << 16) | (g << 8) | b);
// }
