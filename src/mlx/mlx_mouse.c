/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:06:51 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/11 20:17:12 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

/*
xpos -> x coordinate pst
ypos -> x coordinate pst
last_x -> previous x pst

double sensitivity = 0.002; -> pattern to mouse move speed

delta_x -> the movement based on the last last_x
angle -> based in the movement and sensitivity


old_dir_x -> previous 
*/


void mouse_callback(enum mouse_key key, enum action action, enum modifier_key mods, void *param)
{
	t_cube  *cube = param;
	int32_t  x_i, y_i;
	double   xpos, ypos;
	double   delta_x;
	double   angle;
	t_vec    old_dirplane;

	(void)mods;
	if ((key == 0) && (action == MLX_PRESS))
	{
		mlx_get_mouse_pos(cube->mlx, &x_i, &y_i);
		xpos = (double)x_i;
		ypos = (double)y_i;
		if (cube->mouse_lx < 0)
			cube->mouse_lx = xpos;
		delta_x = xpos - cube->mouse_lx;
		cube->mouse_lx = xpos;
		mlx_set_mouse_pos(cube->mlx, WIN_WIDTH / 2, WIN_HEIGHT / 2);
		angle = delta_x * MOUSE_SENS;
		old_dirplane.x = cube->player->dir_x;
		old_dirplane.y = cube->player->plane_x;
		cube->player->dir_x = cube->player->dir_x * cos(angle) - cube->player->dir_y * sin(angle);
		cube->player->dir_y = old_dirplane.x * sin(angle)  + cube->player->dir_y * cos(angle);
		cube->player->plane_x = cube->player->plane_x * cos(angle) - cube->player->plane_y * sin(angle);
		cube->player->plane_y = old_dirplane.y * sin(angle) + cube->player->plane_y * cos(angle);
	}
}
