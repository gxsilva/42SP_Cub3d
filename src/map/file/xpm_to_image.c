/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_to_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 01:13:40 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/08 03:14:44 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

void				init_wall_textures(t_cube *cube);
void			init_img_xpm(t_texture *texture, char *xpm_path);
void			get_dimensions (t_texture *texture, char *xpm_path);
static t_texture	*init_texture_struct (void);

void	init_wall_textures(t_cube *cube)
{
	cube->walls = (t_walls *)malloc(sizeof(t_walls));
	if (!cube->walls)
		error_msg(INVALID_MALLOC, BRIGHT_RED, DEBUG_FLAG, 1);
	cube->walls->ea_data = init_texture_struct();
	cube->walls->no_data = init_texture_struct();
	cube->walls->so_data = init_texture_struct();
	cube->walls->we_data = init_texture_struct();
	init_texture(cube->walls->ea_data, cube->file->ea_path);
	init_texture(cube->walls->no_data, cube->file->no_path);
	init_texture(cube->walls->so_data, cube->file->so_path);
	init_texture(cube->walls->we_data, cube->file->we_path);
}

static t_texture	*init_texture_struct (void)
{
	t_texture	*texture;

	texture = (t_texture *)malloc(sizeof(t_texture));
	if (!texture)
		error_msg(INVALID_MALLOC, BRIGHT_RED, DEBUG_FLAG, 1);
	texture->height = 0;
	texture->width = 0;
	texture->img_ptr = NULL;
	return (texture);
}

void	get_dimensions (t_texture *texture, char *xpm_path)
{
	char	*line;
	char	**xpm_info;

	line = info_xpm_line(xpm_path);
	line = format_xpm_line(line);
	xpm_info = ft_split(line, ' ');
	if (count_elements(xpm_info) != 4)
	{
		free (line);
		free_split ((void **)xpm_info);
		error_msg(INVALID_XPM_FORMAT, BRIGHT_RED, DEBUG_FLAG, 1);
	}
	texture->width = ft_atoi(xpm_info[0]);
	texture->height = ft_atoi(xpm_info[1]);
	free (line);
	free_split ((void **)xpm_info);
}

void	init_img_xpm(t_texture *texture, char *xpm_path)
{
	xpm_t	*xpm;

	xpm = mlx_load_xpm42(xpm_path);
	if (!xpm)
		error_msg(UNABLE_XPM_STRUCT, BRIGHT_RED, DEBUG_FLAG, 1);
	texture->img_ptr = mlx_texture_to_image(get_cube()->mlx, &xpm->texture);
	if (!xpm)
	{
		free (xpm);
		error_msg(UNABLE_XPM_TO_IMG, BRIGHT_RED, DEBUG_FLAG, 1);
	}
	free (xpm);
}


