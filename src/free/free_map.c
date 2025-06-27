/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:59:48 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/25 15:01:06 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

// //!REMOVE (or not ===============================
// static void	tmp_free_buffer_gnl(int fd) 
// {
// 	char	*line;

// 	while ((line = get_next_line(fd)))
// 		free(line);
// 	return ;
// }
// //!============================================

// void	free_map(t_map *map)
// {
// 	if (!map)
// 		return ;
// 	free_split((void **)map->matrix);
// 	tmp_free_buffer_gnl(map->fd);
// 	if (map->fd != -1)
// 		close (map->fd);
// 	free(map);
// }
