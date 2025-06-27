/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cube.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:13:39 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/27 18:19:34 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	free_cube(t_cube *cube);
void	free_file(t_file *file);
void	free_map(t_map *map);
void	free_player (t_player *player);

void	free_cube(t_cube *cube)
{
	free_file(cube->file);
	free_map(cube->map);
	free_player(cube->player);
}


void	free_file(t_file *file)
{
	if (!file)
		return ;
	if (file->ea_path)
		free(file->ea_path);
	if (file->no_path)
		free(file->no_path);
	if (file->so_path)
		free(file->so_path);
	if (file->we_path)
		free(file->we_path);
	free(file);
	file = NULL;
}

void	free_map(t_map *map)
{
	if (!map)
		return ;
	if (map->name)
		free (map->name);
	if (map->matrix)
		free_split((void **)map->matrix);
	free(map);
}

void	free_player (t_player *player)
{
	if (!player)
		return ;
	free (player);
}


