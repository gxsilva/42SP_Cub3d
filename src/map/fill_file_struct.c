/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_file_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:39:09 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/24 20:59:09 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	init_file(t_cube *cube);
char	*normalize_str(char *line);
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

char *normalize_str(char *line)
{
	int		i;

	i = -1;
	while (*line == 32 || *line == '\t')
		line++;
	while (line[++i])
	{
		if (!ft_isascii(line[i]))
			error_msg(INVALID_FILE_CHAR, DEBUG_FLAG, 1);
	}
	return (line);
}

void	fill_directions(char *line, t_file *file)
{
	char	*tmp_line;
	
	if(ft_strnstr(line, "NO", 2))
	{
		tmp_line = normalize_str(line + 2);
		file->NO_path = ft_substr(tmp_line, 0, strlen_space(tmp_line));
	}
	if(ft_strnstr(line, "SO", 2))
	{
		tmp_line = normalize_str(line + 2);
		file->SO_path = ft_substr(tmp_line, 0, strlen_space(tmp_line));
	}
	if(ft_strnstr(line, "WE", 2))
	{
		tmp_line = normalize_str(line + 2);
		file->WE_path = ft_substr(tmp_line, 0, strlen_space(tmp_line));
	}
	if(ft_strnstr(line, "EA", 2))
	{
		tmp_line = normalize_str(line + 2);
		file->EA_path = ft_substr(tmp_line, 0, strlen_space(tmp_line));
	}
}

int	verify_file_info(char *line, t_file *file)
{
	normalize_str(line);
	fill_directions(line, file);
	if (line[1] == '1')
		return (1);
	return (0);
}

void	check_file_origin(t_cube *cube)
{
	char	*line;
	
	init_file(cube);
	line = NULL;
	while (true)
	{
		line = get_next_line(cube->map->fd);
		if (!line)
			printf("reach EOF\n");
		if(verify_file_info(line, cube->file))
			break;
	}
	debug_file_struct(cube->file);
	// verify_fill_file(cube);
}
