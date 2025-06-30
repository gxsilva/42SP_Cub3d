/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:20:03 by ailbezer          #+#    #+#             */
/*   Updated: 2025/06/30 16:35:16 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

void		clean_static(int fd);
void		end_of_map(int fd, char *line);
int			is_empty_line(char *line, int pos);
void		parse_map(t_map *map);

int	is_empty_line(char *line, int pos)
{
	while (line[pos] && (line[pos] == ' ' || line[pos] == '\t'))
		pos++;
	if (!line || (line && line[pos] == '\n'))
		return (1);
	return (0);
}

void	end_of_map(int fd, char *line)
{
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line && !is_empty_line(line, 0))
		{
			free(line);
			clean_static(fd);
			close(fd);
			error_msg(INVALID_EMPTY_LINE, BRIGHT_RED, DEBUG_FLAG, 1);
		}
	}
}

// ! verificar se é preciso mesmo ====
void	leftovers(int fd)
{
	char	*line;

	while ((line = get_next_line(fd)))
		free(line);
}
// !===================================

void	parse_map(t_map *map)
{
	map->start_map = get_start(map->name);
	map->height = get_height(map);
	map->width = get_width(map);
	fill_matrix(map);
	check_walls(map);
	if (DEBUG_FLAG)
	{
		print_map_struct(map);
		print_matrix(map);
		print_player_struct();
	}
	clear_matrix(map);
}
