/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_verify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 21:08:18 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/25 21:18:01 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	verify_file_node(t_file *file)
{
	int valid = 1;

	if (!file->EA_path)
	{
		printf("%s\n", INVALID_EA_XPM);
		valid = 0;
	} 
	if (file->floor < 0)
	{
		printf("%s\n", INVALID_FLOOR_COLOR);
		valid = 0;
	}
	if (file->ceiling < 0)
	{
		printf("%s\n", INVALID_CEILING_COLOR);
		valid = 0;
	}
	return (valid);
}

int		verify_coordinates(t_file *file)
{
	int	valid;

		valid = 1;
		if (!file->NO_path)
		{
			printf("%s\n", INVALID_NO_XPM);
			valid = 0;
		}
		if (!file->SO_path)
		{
			printf("%s\n", INVALID_SO_XPM);
			valid = 0;
		}
		if (!file->WE_path)
		{
			printf("%s\n", INVALID_WE_XPM);
			valid = 0;
		}
		valid = verify_file_node(file); // hate u norm >:|
		return (valid);
}

int	verify_xpm_path(t_file *file)
{
	int		tmp_fd;

	tmp_fd = open(file->EA_path, O_RDONLY);
	if (tmp_fd == -1)
		return (error_stay(INVALID_EA_XPM_PATH));
	close(tmp_fd);
	tmp_fd = open(file->NO_path, O_RDONLY);
	if (tmp_fd == -1)
		return (error_stay(INVALID_NO_XPM_PATH));
	close(tmp_fd);
	tmp_fd = open(file->SO_path, O_RDONLY);
	if (tmp_fd == -1)
		return (error_stay(INVALID_SO_XPM_PATH));
	close(tmp_fd);
	tmp_fd = open(file->WE_path, O_RDONLY);
	if (tmp_fd == -1)
		return (error_stay(INVALID_WE_XPM_PATH));
	close(tmp_fd);
	return (1);
}

// int verify_xmp_duplicate(t_file *file)
// {
// 	if (!ft_strcmp(file->EA_path, file->NO_path) ||
// 		!ft_strcmp(file->EA_path, file->SO_path) ||
// 		!ft_strcmp(file->EA_path, file->WE_path) ||
// 		!ft_strcmp(file->NO_path, file->SO_path) ||
// 		!ft_strcmp(file->NO_path, file->WE_path) ||
// 		!ft_strcmp(file->SO_path, file->WE_path))
// 	{
// 		printf("%s\n", INVALID_DUPLICATE_XPM);
// 		return (0);
// 	}
// 	return (1);
// }

int verify_xpm_extension(t_file *file)
{
	char	*tmp;
	int		cod;
	
	cod = 1;
	tmp = ft_strrchr(file->NO_path, '.');
	if (!tmp || ft_strncmp(tmp, ".xpm", 4))
		cod = error_stay(INVALID_NO_XPM);
	tmp = ft_strrchr(file->SO_path, '.');
	if (!tmp || ft_strncmp(tmp, ".xpm", 4))
		cod = error_stay(INVALID_SO_XPM);
	tmp = ft_strrchr(file->WE_path, '.');
	if (!tmp || ft_strncmp(tmp, ".xpm", 4))
		cod = error_stay(INVALID_WE_XPM);
	return (cod);
}