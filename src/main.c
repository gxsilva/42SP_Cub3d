/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 21:07:48 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/08 16:11:06 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

t_cube	*get_cube(void)
{
	static t_cube	cube;

	return (&cube);
}

void	check_map(char **argv)
{
	char	*tmp;
	int		fd;

	tmp = ft_strrchr(argv[1], '.');
	if (!tmp || ft_strncmp(tmp, ".cub", 4))
		error_msg(INVALID_EXT, BRIGHT_RED, DEBUG_FLAG, 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_msg(INVALID_OPEN, BRIGHT_RED, DEBUG_FLAG, 1);
	tmp = get_next_line(fd);
	if (!tmp)
	{
		free(tmp);
		close(fd);
		error_msg(INVALID_EMPTY_FILE, BRIGHT_RED, DEBUG_FLAG, 1);
	}
	free(tmp);
	clean_static(fd);
	close(fd);
}

void	init_cube(t_cube *cube, char **argv)
{
	check_map(argv);
	init_map(cube, argv);
	// check_file(cube);
	if (DEBUG_FLAG)
		debug_file_struct(cube->file);
	parse_map(cube->map);
}

int	wall_colision_minimap(t_cube *cube)
{
	int	center_x;
	int	center_y;
	// int	size;
	int	map_x;
	int	map_y;

	// size = TILE / 4;
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

void	render_minimap(void *param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	memset(cube->minimap->pixels,
		0,
		cube->minimap->height * cube->minimap->width * sizeof(uint32_t));
	draw_minimap(cube);
	// if (wall_colision_minimap(cube))
	draw_player(cube->minimap, cube->player->pos_x, cube->player->pos_y);
}

void	init_mlx(t_cube *cube)
{
	cube->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "cub3d", false);
	if (!cube->mlx)
		error_msg (UNABLE_INIT_MLX, BRIGHT_RED, DEBUG_FLAG, 1);
	if (DEBUG_FLAG)
		print_color ("MLX initialize", BRIGHT_YELLOW);
	init_textures();
		
	cube->principal_map = mlx_new_image(cube->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!cube->principal_map)
		error_msg (UNABLE_CREAT_MAP, BRIGHT_RED, DEBUG_FLAG, 1);

	cube->minimap = mlx_new_image(cube->mlx, cube->map->width * TILE, cube->map->height * TILE);
	if (!cube->minimap)
		error_msg (UNABLE_CREAT_MINIMAP, BRIGHT_RED, DEBUG_FLAG, 1);	
	// raycast(cube);
	mlx_image_to_window(cube->mlx, cube->principal_map, 0, 0);
	mlx_image_to_window(cube->mlx, cube->minimap, 0, 0);

	mlx_loop_hook(cube->mlx, raycast, cube);
	mlx_loop_hook(cube->mlx, render_minimap, cube);
	
	mlx_key_hook(cube->mlx, set_hooks, cube);
	mlx_loop(cube->mlx);
	mlx_terminate(cube->mlx);
}

int	main(int argc, char **argv)
{
	t_cube	*cube;

	cube = get_cube();
	if (argc != 2)
	{
		printf ("Error\n");
		print_color (INVALID_ARGUMENTS_AMOUNT, BRIGHT_RED);
		return (1);
	}
	init_cube(cube, argv);
	init_mlx(cube);
	free_cube(get_cube());
	return (0);
}
