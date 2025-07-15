/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cube.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:13:39 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/14 19:46:24 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	free_cube(t_cube *cube);
void	free_textures(t_textures *textures);
void	free_file(t_file *file);
void	clear_matrix(t_map *map);

void	free_sprites(t_sprite *sprite)
{
	int		i;

	i = -1;
	if (!sprite)
		return ;
	while (++i < SPRITE_CNT)
		mlx_delete_texture(sprite->frames[i]);
	free (sprite->frames);
	free (sprite);
}

void	free_cube(t_cube *cube)
{
	free_file(cube->file);
	free_map(cube->map);
	free_player(cube->player);
	free_textures(cube->textures);
	free_sprites(cube->sprites);
	if (cube->mlx)
		mlx_terminate(cube->mlx);
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
	if (textures->door)
		mlx_delete_texture(textures->door);
	if (textures->sky)
		mlx_delete_texture(textures->sky);
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
