/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:39:09 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/09 16:57:16 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

void		check_file(t_cube *cube);
void		init_file_struct(t_cube *cube);
int			fill_file_struct(char *line, t_file *file);
int			verify_file_struct(t_file *file);

void	check_file(t_cube *cube)
{
	char	*line;

	init_file_struct(cube);
	while (true)
	{
		line = get_next_line(cube->map->fd);
		if (!line || fill_file_struct(line, cube->file))
		{
			if (line)
				free(line);
			break ;
		}
		free(line);
	}
	clean_static(cube->map->fd);
	if (!verify_file_struct(cube->file))
	{
		printf("Error\n");
		free_cube(cube);
		exit (1);
	}
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
	if (!verify_png_extension(file))
		return (0);
	if (!verify_png_path(file))
		return (0);
	return (1);
}
