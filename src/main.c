/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 21:07:48 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/24 16:55:05 by ailbezer         ###   ########.fr       */
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
}

int main(int argc, char **argv)
{
	t_cube	cube;
	
	(void)argv; //!REMOVE
	if (argc != 2)
	{
		printf ("Error\n");
		printf (INVALID_ARGUMENTS_AMOUNT);
		return(1);
	}
	init_cube(&cube, argv);
	return 0;
}
