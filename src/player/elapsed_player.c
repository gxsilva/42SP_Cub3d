/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elapsed_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:42:08 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/10 18:13:47 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	track_elapsed_time(void *param);

void	track_elapsed_time(void *param)
{
	t_cube	*cube;
	double	current_t;

	cube = (t_cube *)param;
	current_t = mlx_get_time();
	cube->elapsed_t = current_t - cube->last_t;
	cube->last_t = current_t;
}
