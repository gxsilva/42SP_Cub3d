/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cube.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:13:39 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/30 15:07:01 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	free_cube(t_cube *cube);
void	free_file(t_file *file);
void	free_map(t_map *map);
// void	free_player (t_player *player);

void	free_cube(t_cube *cube)
{
	free_file(cube->file);
	free_map(cube->map);
	free_player(cube);
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

void	free_matrix(t_map *map)
{
	int	i;

	i = -1;
	if (!map->matrix)
		return ;
	while (++i < map->height)
			free(map->matrix[i]);
	free(map->matrix);
	map->matrix = NULL;
}

void	free_map(t_map *map)
{
	if (!map)
		return ;
	// ! não precisa mais
	// if (map->name)
	// 	free (map->name);
	if (map->matrix)
		// free_split((void **)map->matrix);
		free_matrix(map);
	if (map->fd > 0)
	{
		leftovers(map->fd);
		close(map->fd);
	}
	free(map);
}

void	free_player (t_cube *cube)
{
	if (!cube->player)
		return ;
	free(cube->player);
	cube->player = NULL;
}
