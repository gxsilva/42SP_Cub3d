/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   png_verify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 21:08:18 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/09 17:24:10 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

static int	verify_file_node(t_file *file, int cod);
int			verify_coordinates(t_file *file);
void		verify_format_path(t_file *file);
int			verify_png_path(t_file *file);
int			verify_png_extension(t_file *file);

int	verify_coordinates(t_file *file)
{
	int	valid;

	valid = 1;
	if (!file->no_path)
		valid = error_stay(INVALID_NO_PNG, BRIGHT_RED);
	if (!file->so_path)
		valid = error_stay(INVALID_SO_PNG, BRIGHT_RED);
	if (!file->we_path)
		valid = error_stay(INVALID_WE_PNG, BRIGHT_RED);
	valid = verify_file_node(file, valid);
	return (valid);
}

int	verify_png_path(t_file *file)
{
	int		tmp_fd;

	tmp_fd = open(file->ea_path, O_RDONLY);
	if (tmp_fd == -1)
		return (error_stay(INVALID_EA_PNG_PATH, BRIGHT_RED));
	close(tmp_fd);
	tmp_fd = open(file->no_path, O_RDONLY);
	if (tmp_fd == -1)
		return (error_stay(INVALID_NO_PNG_PATH, BRIGHT_RED));
	close(tmp_fd);
	tmp_fd = open(file->so_path, O_RDONLY);
	if (tmp_fd == -1)
		return (error_stay(INVALID_SO_PNG_PATH, BRIGHT_RED));
	close(tmp_fd);
	tmp_fd = open(file->we_path, O_RDONLY);
	if (tmp_fd == -1)
		return (error_stay(INVALID_WE_PNG_PATH, BRIGHT_RED));
	close(tmp_fd);
	return (1);
}

int	verify_png_extension(t_file *file)
{
	char	*tmp;
	int		cod;

	cod = 1;
	tmp = ft_strrchr(file->no_path, '.');
	if (!tmp || ft_strncmp(tmp, ".png", 4))
		cod = error_stay(INVALID_NO_PNG, BRIGHT_RED);
	tmp = ft_strrchr(file->ea_path, '.');
	if (!tmp || ft_strncmp(tmp, ".png", 4))
		cod = error_stay(INVALID_EA_PNG, BRIGHT_RED);
	tmp = ft_strrchr(file->so_path, '.');
	if (!tmp || ft_strncmp(tmp, ".png", 4))
		cod = error_stay(INVALID_SO_PNG, BRIGHT_RED);
	tmp = ft_strrchr(file->we_path, '.');
	if (!tmp || ft_strncmp(tmp, ".png", 4))
		cod = error_stay(INVALID_WE_PNG, BRIGHT_RED);
	return (cod);
}

static int	verify_file_node(t_file *file, int cod)
{
	int		valid;

	valid = cod;
	if (!file->ea_path)
		valid = error_stay(INVALID_EA_PNG, BRIGHT_RED);
	return (valid);
}

void	verify_format_path(t_file *file)
{
	if (ft_strncmp(file->ea_path, "./", 2) != 0)
		format_path(&file->ea_path);
	if (ft_strncmp(file->no_path, "./", 2) != 0)
		format_path(&file->no_path);
	if (ft_strncmp(file->so_path, "./", 2) != 0)
		format_path(&file->so_path);
	if (ft_strncmp(file->we_path, "./", 2) != 0)
		format_path(&file->we_path);
}
