/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_initialize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:06:10 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/14 20:04:15 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	init_mlx(t_cube *cube)
{
	int		map_width;
	int		map_height;

	map_width = cube->map->width * TILE;
	map_height = cube->map->height * TILE;
	cube->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "cub3d", false);
	if (!cube->mlx)
		error_msg (UNABLE_INIT_MLX, BRIGHT_RED, DEBUG_FLAG, 1);
	if (DEBUG_FLAG)
		print_color ("MLX initialize", BRIGHT_YELLOW);
	init_textures(cube);
	cube->principal_map = mlx_new_image(cube->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!cube->principal_map)
		error_msg (UNABLE_CREAT_MAP, BRIGHT_RED, DEBUG_FLAG, 1);
	cube->minimap = mlx_new_image(cube->mlx, map_width, map_height);
	if (!cube->minimap)
		error_msg (UNABLE_CREAT_MINIMAP, BRIGHT_RED, DEBUG_FLAG, 1);
}

static void	main_loop(void *param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	if (BONUS)
		mouse_loop_hook(cube->player);
	player_pst(cube);
	track_elapsed_time(cube);
	render_minimap(cube);
	raycast(cube);
	if (BONUS)
		render_doors(cube);
	if (BONUS)
		render_sprite(cube);
}

void	set_mlx_hooks(t_cube *cube)
{
	mlx_set_cursor_mode(cube->mlx, MLX_MOUSE_HIDDEN);
	mlx_set_mouse_pos(cube->mlx, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	mlx_loop_hook(cube->mlx, main_loop, cube);
	mlx_key_hook(cube->mlx, set_hooks, cube);
}

void	cube_loop(t_cube *cube)
{
	set_mlx_hooks(cube);
	mlx_image_to_window(cube->mlx, cube->principal_map, 0, 0);
	if (BONUS)
		mlx_image_to_window(cube->mlx, cube->minimap, 0, 0);
	mlx_loop(cube->mlx);
}
