/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:39:09 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/25 21:14:29 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void		check_file(t_cube *cube);
void		init_file_struct(t_cube *cube);
int			fill_file_struct(char *line, t_file *file);
int			verify_file_struct(t_file *file);

//!REMOVE (or not ===============================
static void	tmp_free_buffer_gnl(int fd) 
{
	char	*line;

	while((line = get_next_line(fd)))
		free(line);
	return ;
}
//!============================================

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
	//?WIP
	tmp_free_buffer_gnl(cube->map->fd); //!REMOVE
	if(!verify_file_struct(cube->file))
		exit (1);
	debug_file_struct(cube->file);//!REMOVE
	free_file(cube->file);
}

void init_file_struct(t_cube *cube)
{
	cube->file = (t_file *)malloc(sizeof(t_file));
	if (!cube->file)
		error_msg(INVALID_MALLOC, DEBUG_FLAG, 1);
	cube->file->ceiling = -1;
	cube->file->floor = -1;
	cube->file->EA_path = NULL;
	cube->file->NO_path = NULL;
	cube->file->SO_path = NULL;
	cube->file->WE_path = NULL;
}

int	fill_file_struct(char *line, t_file *file)
{
	char	*tmp_line;

	tmp_line = sanitize_string(line);
	if (*tmp_line == '\0')
		return (0);
	if (tmp_line[0] == '1' || tmp_line[0] == '0')
		return (1);
	fill_directions(tmp_line, file);
	fill_floor_ceiling(tmp_line, file);
	return (0);
}

int	verify_file_struct(t_file *file)
{
	if (!verify_coordinates(file))//0 = error
		return (0);
	// if (!verify_xmp_duplicate(file))//0 = error
	// 	return (0);
	if (!verify_xpm_extension(file)) //0 = error
		return (0);
	if (!verify_xpm_path(file)) //0 = error
		return (0);
	return (1);
}

