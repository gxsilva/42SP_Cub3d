/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 21:07:48 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/14 20:03:42 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	init_cube(t_cube *cube, char **argv);
void	check_map(char **argv);
int		main(int argc, char **argv);

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
	cube_loop(cube);
	free_cube(get_cube());
	return (0);
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
	check_file(cube);
	if (DEBUG_FLAG)
		debug_file_struct(cube->file);
	init_sprites(cube);
	parse_map(cube->map);
	cube->mouse_lx = -1;
}
