/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:22:33 by ailbezer          #+#    #+#             */
/*   Updated: 2025/07/13 21:42:28 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

int		width_len(char *line, int fd);
int		get_width(t_map *map);
int		get_height(t_map *map);
int		get_start(char *map_name);
char	*jump_to_map(t_map *map, char *line, int fd);

int	width_len(char *line, int fd)
{
	char	*start;
	char	*end;
	int		width;

	start = ft_strchr(line, '1');
	end = ft_strrchr(line, '1');
	width = end - start;
	if (line[width] && !ft_strchr("10NSEWC\n\t ", line[width]))
	{
		close(fd);
		free(line);
		error_msg(INVALID_PLAYER_DIR, BRIGHT_RED, DEBUG_FLAG, 1);
	}
	return (width + 1);
}

int	get_width(t_map *map)
{
	int		fd;
	int		width;
	char	*line;

	line = NULL;
	width = 0;
	fd = open(map->name, O_RDONLY);
	line = jump_to_map(map, line, fd);
	while (line && !is_empty_line(line, 0))
	{
		if (width_len(line, fd) > width)
			width = width_len(line, fd);
		free(line);
		line = get_next_line(fd);
	}
	end_of_map(fd, line);
	close(fd);
	return (width);
}

int	get_height(t_map *map)
{
	int		fd;
	int		height;
	char	*line;

	line = NULL;
	height = 0;
	fd = open(map->name, O_RDONLY);
	line = jump_to_map(map, line, fd);
	while (line && !is_empty_line(line, 0))
	{
		free(line);
		height++;
		line = get_next_line(fd);
	}
	end_of_map(fd, line);
	close(fd);
	return (height);
}

int	get_start(char *map_name)
{
	int		fd;
	char	*line;
	int		i;
	int		start;

	fd = open(map_name, O_RDONLY);
	start = 0;
	while (true)
	{
		i = 0;
		line = get_next_line(fd);
		while (line && line[i] && (line[i] == ' ' || line[i] == '\t'))
			i++;
		check_wall_init(line, fd, i);
		if (!line || (line[i] && line[i] == '1'))
			break ;
		start++;
		free(line);
	}
	clean_static(fd);
	close(fd);
	if (!line)
		error_msg(INVALID_MISSING_MAP, BRIGHT_RED, DEBUG_FLAG, 1);
	free(line);
	return (start);
}

char	*jump_to_map(t_map *map, char *line, int fd)
{
	int	i;

	i = -1;
	while (++i <= map->start_map)
	{
		if (line)
			free(line);
		line = get_next_line(fd);
	}
	return (line);
}
