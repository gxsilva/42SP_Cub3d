/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:35:54 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/26 17:40:46 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	free_file(t_file *file)
{
	if (!file)
		return ;
	if (file->ea_path)
		free(file->ea_path);
	if (file->no_path)
		free(file->no_path);
	if (file->so_path)
		free(file->so_path);
	if (file->we_path)
		free(file->we_path);
	free(file);
	file = NULL;
}
