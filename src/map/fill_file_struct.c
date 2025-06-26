/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_file_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:53:09 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/26 17:11:47 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	fill_directions(char *line, t_file *file);
void	fill_floor_ceiling(char *line, t_file *file);

void	fill_directions(char *line, t_file *file)
{
	char	*line_buffer;
	
	if (ft_strnstr(line, "NO", 2))
	{
		if (file->NO_path != NULL)
			error_msg(INVALID_NO_DUPLICATE, DEBUG_FLAG, 1);
		line_buffer = sanitize_string(line + 2);
		file->NO_path = ft_substr(line_buffer, 0, strlen_space(line_buffer));
	}
	else if (ft_strnstr(line, "SO", 2))
	{
		if (file->SO_path != NULL)
			error_msg(INVALID_SO_DUPLICATE, DEBUG_FLAG, 1);
		line_buffer = sanitize_string(line + 2);
		file->SO_path = ft_substr(line_buffer, 0, strlen_space(line_buffer));
	}
	else if (ft_strnstr(line, "WE", 2))
	{
		if (file->WE_path != NULL)
			error_msg(INVALID_WE_DUPLICATE, DEBUG_FLAG, 1);
		line_buffer = sanitize_string(line + 2);
		file->WE_path = ft_substr(line_buffer, 0, strlen_space(line_buffer));
	}
	else if (ft_strnstr(line, "EA", 2))
	{
		if (file->EA_path != NULL)
			error_msg(INVALID_EA_DUPLICATE, DEBUG_FLAG, 1);
		line_buffer = sanitize_string(line + 2);
		file->EA_path = ft_substr(line_buffer, 0, strlen_space(line_buffer));
	}
}

void	fill_floor_ceiling(char *line, t_file *file)
{
	char	*line_buffer;
	char	*color_buffer;
	int		color;
	
	color_buffer = NULL;
	if (ft_strnstr(line, "F", 1))
	{
		line_buffer = sanitize_string(line + 1);
		color_buffer = ft_substr(line_buffer, 0, ft_strlen(line_buffer));
		color = rgb_to_int(color_buffer);
		if (color == -1) //TODO isso vai causar leak, Fake global vai com o free recursivo vai resolver
			error_msg(INVALID_COLOR_FORMAT, DEBUG_FLAG, 1);
		file->floor = color;
	}
	else if (ft_strnstr(line, "C", 1))
	{
		line_buffer = sanitize_string(line + 1);
		color_buffer = ft_substr(line_buffer, 0, ft_strlen(line_buffer));
		color = rgb_to_int(color_buffer);
		if (color == -1)
			error_msg(INVALID_COLOR_FORMAT, DEBUG_FLAG, 1);
		file->ceiling = color;
	}
	if (color_buffer)
		free(color_buffer);
}