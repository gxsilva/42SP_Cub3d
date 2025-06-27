/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:46:11 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/27 15:37:08 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	init_map(t_cube *cube, char **argv);

void	init_map(t_cube *cube, char **argv)
{
	cube->map = (t_map *)malloc(sizeof(t_map));
	if (!cube->map)
		error_msg(INVALID_MALLOC, BRIGHT_RED, DEBUG_FLAG, 1);
	cube->map->fd = open(argv[1], O_RDONLY);
	cube->map->height = 0;
	cube->map->width = 0;
	cube->map->matrix = NULL;
}
