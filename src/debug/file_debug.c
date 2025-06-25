/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_debug.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:30:51 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/24 20:54:02 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	debug_file_struct(t_file *file)
{
	printf("File struct information:\n");
	printf("Ceiling: %d\n", file->ceiling);
	printf("Floor: %d\n", file->floor);
	printf("EA_path: %s\n", file->EA_path);
	printf("NO_path: %s\n", file->NO_path);
	printf("SO_path: %s\n", file->SO_path);
	printf("WE_path: %s\n", file->WE_path);
}