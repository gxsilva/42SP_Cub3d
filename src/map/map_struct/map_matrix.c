/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:18:35 by ailbezer          #+#    #+#             */
/*   Updated: 2025/07/14 19:32:37 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

void	alloc_matrix(t_map *map);
void	put_in_matrix(t_map *map, int i, int *j, char *line);
void	fill_matrix(t_map *map);

void	alloc_matrix(t_map *map)
{
	int	i;

	i = -1;
	map->matrix = (int **)malloc(map->height * sizeof(int *));
	if (!map->matrix)
		return ;
	while (++i < map->height)
	{
		map->matrix[i] = (int *)malloc(map->width * sizeof(int));
		if (!map->matrix[i])
		{
			while (--i >= 0)
				free(map->matrix[i]);
			free(map->matrix);
			map->matrix = NULL;
			return ;
		}
	}
}

void	put_in_matrix(t_map *map, int i, int *j, char *line)
{
	if (ft_isdigit(line[*j]))
		map->matrix[i][*j] = line[*j] - 48;
	else if (ft_strchr("NSWE", line[*j]))
	{
		(get_cube())->player = init_player(i, j, line[*j]);
		map->matrix[i][*j] = 0;
	}
	else if (line[*j] == 'D')
		map->matrix[i][*j] = 3;
	else if (line[*j] == 'C')
	{
		get_cube()->sprites->x = *j;
		get_cube()->sprites->y = i;
		map->matrix[i][*j] = 5;
	}
	else if (line[*j] == '\n')
	{
		while (*j < map->width)
			map->matrix[i][(*j)++] = 2;
	}
	else
		map->matrix[i][*j] = 2;
}

void	fill_matrix(t_map *map)
{
	int		fd;
	int		i;
	int		j;
	char	*line;
	int		start;

	line = NULL;
	fd = open(map->name, O_RDONLY);
	alloc_matrix(map);
	line = jump_to_map(map, line, fd);
	i = -1;
	start = ft_strlen(line) - map->width - 1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
			put_in_matrix(map, i, &j, line + start);
		free(line);
		line = get_next_line(fd);
	}
	clean_static(fd);
	free(line);
	close(fd);
	if (!(get_cube())->player)
		error_msg(INVALID_PLAYER_COUNT, BRIGHT_RED, DEBUG_FLAG, 1);
}
