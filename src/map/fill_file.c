/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:39:09 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/27 18:49:57 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void		check_file(t_cube *cube);
void		init_file_struct(t_cube *cube);
int			fill_file_struct(char *line, t_file *file);
int			verify_file_struct(t_file *file);


// //!REMOVE (or not ===============================
static void	tmp_free_buffer_gnl(int fd) 
{
	char	*line;

	while ((line = get_next_line(fd)))
		free(line);
	return ;
}
// //!============================================

void	check_file(t_cube *cube)
{
	char	*line;
	int		fd;

	init_file_struct(cube);
	fd = open(cube->map->name, O_RDONLY);
	while (true)
	{
		line = get_next_line(fd);
		if (!line || fill_file_struct(line, cube->file))
		{
			if (line)
				free(line);
			break ;
		}
		free(line);
	}
	tmp_free_buffer_gnl(fd);
	close(fd);
	if (!verify_file_struct(cube->file))
	{
		// free_map(cube->map);
		free_file(cube->file);
		exit (1);
	}
	if (DEBUG_FLAG)
		debug_file_struct(cube->file);
}

void	init_file_struct(t_cube *cube)
{
	cube->file = (t_file *)malloc(sizeof(t_file));
	if (!cube->file)
		error_msg(INVALID_MALLOC, BRIGHT_RED, DEBUG_FLAG, 1);
	cube->file->ceiling = -1;
	cube->file->floor = -1;
	cube->file->ea_path = NULL;
	cube->file->no_path = NULL;
	cube->file->so_path = NULL;
	cube->file->we_path = NULL;
}

int	fill_file_struct(char *line, t_file *file)
{
	char	*line_buffer;

	line_buffer = sanitize_string(line);
	if (*line_buffer == '\0')
		return (0);
	if (line_buffer[0] == '1' || line_buffer[0] == '0')
		return (1);
	fill_directions(line_buffer, file);
	fill_floor_ceiling(line_buffer, file);
	return (0);
}

int	verify_file_struct(t_file *file)
{
	if (!verify_coordinates(file))
		return (0);
	verify_format_path(file);
	if (!verify_xpm_extension(file))
		return (0);
	if (!verify_xpm_path(file))
		return (0);
	return (1);
}
