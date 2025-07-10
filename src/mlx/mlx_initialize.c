/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_initialize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:06:10 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/10 18:06:29 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	init_mlx(t_cube *cube)
{
	cube->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "cub3d", false);
	if (!cube->mlx)
		error_msg (UNABLE_INIT_MLX, BRIGHT_RED, DEBUG_FLAG, 1);
	if (DEBUG_FLAG)
		print_color ("MLX initialize", BRIGHT_YELLOW);
	init_textures(cube);
		
	cube->principal_map = mlx_new_image(cube->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!cube->principal_map)
		error_msg (UNABLE_CREAT_MAP, BRIGHT_RED, DEBUG_FLAG, 1);

	cube->minimap = mlx_new_image(cube->mlx, cube->map->width * TILE, cube->map->height * TILE);
	if (!cube->minimap)
		error_msg (UNABLE_CREAT_MINIMAP, BRIGHT_RED, DEBUG_FLAG, 1);
}

void	set_mlx_hooks(t_cube *cube)
{
	mlx_loop_hook(cube->mlx, raycast, cube);
	mlx_loop_hook(cube->mlx, render_minimap, cube);
	mlx_loop_hook(cube->mlx, player_pst, cube);
	mlx_loop_hook(cube->mlx, track_elapsed_time, cube);
	mlx_key_hook(cube->mlx, set_hooks, cube);
}

void	cube_loop(t_cube *cube)
{
	set_mlx_hooks(cube);
	mlx_image_to_window(cube->mlx, cube->principal_map, 0, 0);
	mlx_image_to_window(cube->mlx, cube->minimap, 0, 0);
	mlx_loop(cube->mlx);
	mlx_terminate(cube->mlx);
}