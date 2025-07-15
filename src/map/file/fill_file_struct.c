/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_file_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:53:09 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/09 17:25:25 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

void			fill_directions(char *line, t_file *file);
void			fill_floor_ceiling(char *line, t_file *file);
static void		fill_directions_node(char *line, t_file *file);

static void	fill_directions_node(char *line_buffer, t_file *file)
{
	if (ft_strnstr(line_buffer, "WE", 2))
	{
		if (file->we_path != NULL)
		{
			free(line_buffer);
			error_msg(INVALID_WE_DUPLICATE, BRIGHT_RED, DEBUG_FLAG, 1);
		}
		line_buffer = sanitize_string(line_buffer + 2);
		file->we_path = ft_substr(line_buffer, 0, strlen_space(line_buffer));
	}
	else if (ft_strnstr(line_buffer, "EA", 2))
	{
		if (file->ea_path != NULL)
		{
			free(line_buffer);
			error_msg(INVALID_EA_DUPLICATE, BRIGHT_RED, DEBUG_FLAG, 1);
		}
		line_buffer = sanitize_string(line_buffer + 2);
		file->ea_path = ft_substr(line_buffer, 0, strlen_space(line_buffer));
	}
}

void	fill_directions(char *line, t_file *file)
{
	char	*line_buffer;

	line_buffer = NULL;
	if (ft_strnstr(line, "NO", 2))
	{
		if (file->no_path != NULL)
			error_msg(INVALID_NO_DUPLICATE, BRIGHT_RED, DEBUG_FLAG, 1);
		line_buffer = sanitize_string(line + 2);
		file->no_path = ft_substr(line_buffer, 0, strlen_space(line_buffer));
	}
	else if (ft_strnstr(line, "SO", 2))
	{
		if (file->so_path != NULL)
			error_msg(INVALID_SO_DUPLICATE, BRIGHT_RED, DEBUG_FLAG, 1);
		line_buffer = sanitize_string(line + 2);
		file->so_path = ft_substr(line_buffer, 0, strlen_space(line_buffer));
	}
	fill_directions_node(line, file);
}

void	fill_floor_ceiling(char *line, t_file *file)
{
	char		*line_buffer;
	char		*color_buffer;
	uint32_t	color;

	color_buffer = NULL;
	if (ft_strnstr(line, "F", 1))
	{
		line_buffer = sanitize_string(line + 1);
		color_buffer = ft_substr(line_buffer, 0, ft_strlen(line_buffer));
		color = rgba_to_int(color_buffer);
		file->floor = color;
	}
	if (ft_strnstr(line, "C", 1))
	{
		line_buffer = sanitize_string(line + 1);
		color_buffer = ft_substr(line_buffer, 0, ft_strlen(line_buffer));
		color = rgba_to_int(color_buffer);
		file->ceiling = color;
	}
	if (color_buffer)
		free(color_buffer);
}
