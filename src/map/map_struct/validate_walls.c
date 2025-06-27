/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:15:59 by ailbezer          #+#    #+#             */
/*   Updated: 2025/06/27 19:02:06 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

void	check_wall_init(char *line, int fd, int i);
void	north_and_south(t_map *map);
void	check_walls(t_map *map);

void	check_wall_init(char *line, int fd, int i)
{
	if (line[i] == '0')
	{
		close(fd);
		free(line);
		// ! funcão de liberar matrix
		error_msg(INVALID_WALLS_FORMAT, BRIGHT_RED, DEBUG_FLAG, 1);
	}
}

void	north_and_south(t_map *map)
{
	int	x;
	int	y;

	x = -1;
	while (++x < map->width)
	{
		y = 0;
		while (y < map->height - 1 && map->matrix[y][x] == 2)
			y++;
		if (map->matrix[y][x] != 1 && map->matrix[y][x] != 2)
			error_msg(INVALID_WALLS_FORMAT, BRIGHT_RED, DEBUG_FLAG, 1);
	}
	x = -1;
	while (++x < map->width)
	{
		y = map->height - 1;
		while (y <= 0 && map->matrix[y][x] == 2)
			y--;
		if (map->matrix[y][x] != 1 && map->matrix[y][x] != 2)
			error_msg(INVALID_WALLS_FORMAT, BRIGHT_RED, DEBUG_FLAG, 1);
	}
}

void	check_walls(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->height)
	{
		x = 0;
		while (y < map->width && map->matrix[y][x] == 2)
			x++;
		if (map->matrix[y][x] != 1)
			error_msg(INVALID_WALLS_FORMAT, BRIGHT_RED, DEBUG_FLAG, 1);
	}
	y = -1;
	while (++y < map->height)
	{
		x = map->width - 1;
		while (map->matrix[y][x] == 2)
			x--;
		if (map->matrix[y][x] != 1)
			error_msg(INVALID_WALLS_FORMAT, BRIGHT_RED,  DEBUG_FLAG, 1);
	}
	north_and_south(map);
}
