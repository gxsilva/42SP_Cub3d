/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cube_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:15:46 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/10 18:16:07 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	free_map(t_map *map);
void	free_player(t_player *player);

void	free_map(t_map *map)
{
	if (!map)
		return ;
	if (map->matrix)
		clear_matrix(map);
	if (map->fd > 0)
	{
		clean_static(map->fd);
		close(map->fd);
	}
	free(map);
}

void	free_player(t_player *player)
{
	if (!player)
		return ;
	free(player);
	player = NULL;
}
