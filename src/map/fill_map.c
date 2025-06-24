/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:46:11 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/24 15:58:39 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	init_map(t_cube *cube);

void	init_map(t_cube *cube)
{
	cube->map = (t_map *)malloc(sizeof(t_map));
	if (!cube->map)
		error_msg(INVALID_MALLOC, DEBUG_FLAG, 1);
	cube->map->fd = 0;
	cube->map->height = 0;
	cube->map->width = 0;
	cube->map->matrix = NULL;
}
