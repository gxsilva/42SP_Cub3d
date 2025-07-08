/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cube.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:13:39 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/08 03:16:23 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	free_cube(t_cube *cube);
void	free_file(t_file *file);
void	free_map(t_map *map);
void	free_player(t_player *player);

void	free_texture(t_texture *texture)
{
	if (!texture)
		return ;
	// if (texture->img_ptr)
	// 	mlx_delete_image(get_cube()->mlx, texture->img_ptr);
	free(texture);
}

void	free_walls(t_walls *walls)
{
	if (!walls)
		return ;
	if (walls->no_data)
		free_texture(walls->no_data);
	if (walls->so_data)
		free_texture(walls->so_data);
	if (walls->we_data)
		free_texture(walls->we_data);
	if (walls->ea_data)
		free_texture(walls->ea_data);
	free(walls);
}

void	free_cube(t_cube *cube)
{
	free_file(cube->file);
	free_map(cube->map);
	free_player(cube->player);
	free_walls(cube->walls);
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

void	clear_matrix(t_map *map)
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
