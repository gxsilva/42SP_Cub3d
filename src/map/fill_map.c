/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:46:11 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/27 18:53:50 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	init_map(t_cube *cube, char **argv);

void	init_map(t_cube *cube, char **argv)
{
	cube->map = (t_map *)malloc(sizeof(t_map));
	if (!cube->map)
	  error_msg(INVALID_MALLOC, BRIGHT_RED, DEBUG_FLAG, 1);
	cube->map->height = 0;
	cube->map->name = ft_strdup(argv[1]);
	cube->map->width = 0;
	cube->map->matrix = NULL;
	cube->player = NULL;
}
