/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 19:45:05 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/13 19:45:11 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	interact_with_door(mlx_key_data_t keydata, t_cube *cube)
{
	int	dx;
	int	dy;

	dx = (int)floor(cube->player->pos_x + cube->player->dir_x);
	dy = (int)floor(cube->player->pos_y + cube->player->dir_y);
	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
	{
		if (cube->map->matrix[dy][dx] == 3)
			cube->map->matrix[dy][dx] = 4;
	}
}
