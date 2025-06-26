/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 21:07:48 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/26 17:30:29 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	check_map(char **argv)
{
	char	*tmp;
	int		fd;

	tmp = ft_strrchr(argv[1], '.');
	if (!tmp || ft_strncmp(tmp, ".cub", 4))
		error_msg(INVALID_EXT, DEBUG_FLAG, 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_msg(INVALID_OPEN, DEBUG_FLAG, 1);
	close(fd);
}

void	init_cube(t_cube *cube, char **argv)
{
	check_map(argv);
	init_map(cube, argv);
	//? try to recieve the fd to call 'check_file' first than 'init_map'
	check_file(cube);
}

int	main(int argc, char **argv)
{
	t_cube	cube;

	(void)argv; //!REMOVE
	if (argc != 2)
	{
		printf ("Error\n");
		printf ("%s\n", INVALID_ARGUMENTS_AMOUNT);
		return (1);
	}
	init_cube(&cube, argv);
	//? to prevent leak (for now)
	free_map (cube.map);
	free_file(cube.file);
	return (0);
}
