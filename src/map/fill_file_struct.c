/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_file_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:39:09 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/25 02:27:40 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	init_file(t_cube *cube);
char	*sanitize_string(char *line);
void	fill_directions(char *line, t_file *file);
int		verify_file_info(char *line, t_file *file);
void	check_file_origin(t_cube *cube);

void init_file(t_cube *cube)
{
	cube->file = (t_file *)malloc(sizeof(t_file));
	if (!cube->file)
		error_msg(INVALID_MALLOC, DEBUG_FLAG, 1);
	cube->file->ceiling = 0;
	cube->file->floor = 0;
	cube->file->EA_path = NULL;
	cube->file->NO_path = NULL;
	cube->file->SO_path = NULL;
	cube->file->WE_path = NULL;
}

char *sanitize_string(char *line)
{
	if (!line)
		error_msg(NULL_POINTER, DEBUG_FLAG, 1);
	while (*line == ' ' || *line == '\t')
		line++;
	for (int i = 0; line[i]; i++)
	{
		if (!ft_isascii(line[i]))
			error_msg(INVALID_FILE_CHAR, DEBUG_FLAG, 1);
	}
	return line;
}

void	fill_directions(char *line, t_file *file)
{
	char	*line_buffer;

	line_buffer = sanitize_string(line);
	if (ft_strnstr(line, "NO", 2) && !file->NO_path)
	{
		line_buffer = sanitize_string(line + 2);
		file->NO_path = ft_substr(line_buffer, 0, strlen_space(line_buffer));
	}
	else if (ft_strnstr(line, "SO", 2) && !file->SO_path)
	{
		line_buffer = sanitize_string(line + 2);
		file->SO_path = ft_substr(line_buffer, 0, strlen_space(line_buffer));
	}
	else if (ft_strnstr(line, "WE", 2) && !file->WE_path)
	{
		line_buffer = sanitize_string(line + 2);
		file->WE_path = ft_substr(line_buffer, 0, strlen_space(line_buffer));
	}
	else if (ft_strnstr(line, "EA", 2) && !file->EA_path)
	{
		line_buffer = sanitize_string(line + 2);
		file->EA_path = ft_substr(line_buffer, 0, strlen_space(line_buffer));
	}
}

int count_elements(char **array)
{
	int count = 0;

	if (!array)
		return 0;
	while (array[count] != NULL)
		count++;
	return count;
}

int		rgb_to_int(char *str)
{
	int		color;
	char	**rgb;

	rgb = ft_split(str, ',');
	if (count_elements(rgb) != 3)
		return (-1);
	color = (ft_atoi(rgb[0]) << 16) | (ft_atoi(rgb[1]) << 8) | ft_atoi(rgb[2]);
	return (color);
}

void	fill_floor_ceiling(char *line, t_file *file)
{
	char	*line_buffer;
	char	*tmp_color;
	int		color;
	
	line_buffer = sanitize_string(line);
	if (ft_strnstr(line, "F", 1) && !file->floor)
	{
		line_buffer = sanitize_string(line + 1);
		tmp_color = ft_substr(line_buffer, 0, strlen_space(line_buffer));
		color = rgb_to_int(tmp_color);
		if (color == -1)
			error_msg(INVALID_COLOR_FORMAT, DEBUG_FLAG, 1);
		file->floor = color;
	}
	else if (ft_strnstr(line, "C", 1) && !file->ceiling)
	{
		line_buffer = sanitize_string(line + 1);
		tmp_color = ft_substr(line_buffer, 0, strlen_space(line_buffer));
		color = rgb_to_int(tmp_color);
		if (color == -1)
			error_msg(INVALID_COLOR_FORMAT, DEBUG_FLAG, 1);
		file->ceiling = color;
	}
}

int	verify_file_info(char *line, t_file *file)
{
	sanitize_string(line);
	fill_directions(line, file);
	fill_floor_ceiling(line, file);
	if (line[0] == '1' || line[0] == '0')
		return (1);
	return (0);
}

void	check_file_origin(t_cube *cube)
{
	char	*line;
	
	init_file(cube);
	while (true)
	{
		line = get_next_line(cube->map->fd);
		if (!line || verify_file_info(line, cube->file))
			break ;
	}
	debug_file_struct(cube->file);
	// verify_fill_file(cube);
}
