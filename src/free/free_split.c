/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:54:11 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/25 14:59:13 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	free_split(void **matrix)
{
	int		i;

	i = -1;
	if (!matrix || !(*matrix))
		return ;
	while(matrix[++i])
		if (matrix[i])
			free(matrix[i]);
	free(matrix);
}