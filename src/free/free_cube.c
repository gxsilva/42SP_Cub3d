/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cube.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:13:39 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/09 20:18:42 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	free_cube(t_cube *cube);
void	free_file(t_file *file);
void	free_map(t_map *map);
void	free_player(t_player *player);
void	free_textures(t_textures *textures);

void	free_cube(t_cube *cube)
{
	free_file(cube->file);
	free_map(cube->map);
	free_player(cube->player);
	free_textures(cube->textures);
}

void	free_textures(t_textures *textures)
{
	if (!textures)
		return ;
	if (textures->north)
		mlx_delete_texture(textures->north);
	if (textures->south)
		mlx_delete_texture(textures->south);
	if (textures->east)
		mlx_delete_texture(textures->east);
	if (textures->west)
		mlx_delete_texture(textures->west);
	free(textures);
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
