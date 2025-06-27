/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:20:03 by ailbezer          #+#    #+#             */
/*   Updated: 2025/06/27 16:19:51 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	leftovers(int fd);
int		width_len(char *line, int fd);
char	*jump_to_map(t_map *map, char *line, int fd);

//============================= DEBUG ==============================
// void print_map(char *line, int fd)
// {
// 	int i;

// 	printf("%s", line);
// 	while (1 && line)
// 	{
// 		i = 0;
// 		free(line);
// 		line = get_next_line(fd);
// 		if (line)
// 			printf("%s", line);
// 	}
// }

void	print_map_struct(t_map *map)
{
	printf(YELLOW"========== MAP STRUCT =========\n"RESET);
	printf("START_LINE:\t%d\n", map->start_map);
	printf("HEIGHT:\t\t%d\n", map->height);
	printf("WIDTH:\t\t%d\n", map->width);
	printf(YELLOW"===============================\n"RESET);
}

void	print_matrix(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	printf(YELLOW"========== MATRIX =========\n"RESET);
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->matrix[i][j] == 2)
				printf(RED"%d"RESET, map->matrix[i][j]);
			else if (map->matrix[i][j] == 1)
				printf(GREEN"%d"RESET, map->matrix[i][j]);
			if (map->matrix[i][j] == 0)
				printf(BLUE"%d"RESET, map->matrix[i][j]);
		}
		printf("\n");
	}
	printf(YELLOW"===============================\n"RESET);
}

void	print_player_struct(void)
{
	t_player	*player;

	player = get_cube()->player;
	printf(YELLOW"=========== PLAYER ============\n"RESET);
	printf("POS_X: %d\n", player->map_pos_x);
	printf("POS_Y: %d\n", player->map_pos_y);
	printf("DIR_X: %d\n", player->dir_x);
	printf("DIR_Y: %d\n", player->dir_y);
	printf(YELLOW"===============================\n"RESET);
}

//================================================================

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
			close(fd);
			free(line);
			error_msg(INVALID_EMPTY_LINE, DEBUG_FLAG, 1);
		}
	}
}

int	width_len(char *line, int fd)
{
	char	*start;
	char	*end;
	int		width;

	start = ft_strchr(line, '1');
	end = ft_strrchr(line, '1');
	width = end - start;
	if (line[width] && !ft_strchr("10NSEW\n\t ", line[width]))
	{
		close(fd);
		free(line);
		error_msg(INVALID_CARACTER, DEBUG_FLAG, 1);
	}
	return (width + 1);
}

int	get_width(t_map *map)
{
	int		i;
	int		fd;
	int		width;
	char	*line;

	line = NULL;
	i = -1;
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
	int		i;
	int		fd;
	int		height;
	char	*line;

	line = NULL;
	i = -1;
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

void	check_wall_init(char *line, int fd, int i)
{
	if (line[i] == '0')
	{
		close(fd);
		free(line);
		//  funcão de liberar matrix
		error_msg(INVALID_WALLS_FORMAT, DEBUG_FLAG, 1);
	}
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
		while (line[i] && (line[i] == ' ' || line[i] == '\t'))
			i++;
		check_wall_init(line, fd, i);
		if (line[i] == '1')
			break ;
		start++;
		free(line);
	}
	leftovers(fd);
	close(fd);
	free(line);
	return (start);
}

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

t_player	*set_player(int i, int *j, char dir)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	player->map_pos_x = *j;
	player->map_pos_y = i;
	if (dir == 'N' || dir == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		if (dir == 'S')
			player->dir_y = -1;
	}
	else if (dir == 'E' || dir == 'W')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		if (dir == 'W')
			player->dir_x = -1;
	}
	return (player);
}

void	put_in_matrix(t_map *map, int i, int *j, char *line)
{
	if (ft_isdigit(line[*j]))
		map->matrix[i][*j] = line[*j] - 48;
	else if (ft_strchr("NSWE", line[*j]))
	{
		(get_cube())->player = set_player(i, j, line[*j]);
		map->matrix[i][*j] = 0;
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
	leftovers(fd);
	free(line);
	close(fd);
}

void	leftovers(int fd)
{
	char	*line;

	while ((line = get_next_line(fd)))
		free(line);
}

void	clear_matrix(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
		free(map->matrix[i++]);
	free(map->matrix);
	map->matrix = NULL;
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
			error_msg(INVALID_WALLS_FORMAT, DEBUG_FLAG, 1);
	}
	x = -1;
	while (++x < map->width)
	{
		y = map->height - 1;
		while (y <= 0 && map->matrix[y][x] == 2)
			y--;
		if (map->matrix[y][x] != 1 && map->matrix[y][x] != 2)
			error_msg(INVALID_WALLS_FORMAT, DEBUG_FLAG, 1);
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
			error_msg(INVALID_WALLS_FORMAT, DEBUG_FLAG, 1);
	}
	y = -1;
	while (++y < map->height)
	{
		x = map->width - 1;
		while (map->matrix[y][x] == 2)
			x--;
		if (map->matrix[y][x] != 1)
			error_msg(INVALID_WALLS_FORMAT, DEBUG_FLAG, 1);
	}
	north_and_south(map);
}

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
