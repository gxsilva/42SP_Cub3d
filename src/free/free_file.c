/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:35:54 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/25 14:38:28 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	free_file(t_file *file)
{
	if (!file)
		return ;
	if (file->EA_path)
		free(file->EA_path);
	if (file->NO_path)
		free(file->NO_path);
	if (file->SO_path)
		free(file->SO_path);
	if (file->WE_path)
		free(file->WE_path);
	free(file);
	file = NULL;
}