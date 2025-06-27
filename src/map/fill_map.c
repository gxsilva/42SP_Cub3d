/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:46:11 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/26 20:32:01 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	init_map(t_cube *cube, char **argv);

void	init_map(t_cube *cube, char **argv)
{
	cube->map = (t_map *)malloc(sizeof(t_map));
	if (!cube->map)
		error_msg(INVALID_MALLOC, DEBUG_FLAG, 1);
	// cube->map->fd = open(argv[1], O_RDONLY);
	cube->map->name = argv[1];
	cube->map->height = 0;
	cube->map->width = 0;
	cube->map->matrix = NULL;

	cube->player = NULL;
}
