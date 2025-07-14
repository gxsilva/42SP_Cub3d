/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:06:51 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/14 16:20:58 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	mouse_loop_hook(void *param)
{
	double		angle;
	t_vec		od;
	int32_t		cx;
	int32_t		mx;
	int32_t		my;

	mlx_get_mouse_pos(get_cube()->mlx, &mx, &my);
	cx = WIN_WIDTH / 2;
	angle = (mx - cx) * MOUSE_SENS;
	if (angle != 0.0)
	{
		od.x = ((t_player *)param)->dir_x;
		od.y = ((t_player *)param)->dir_y;
		((t_player *)param)->dir_x = od.x * cos(angle) - od.y * sin(angle);
		((t_player *)param)->dir_y = od.x * sin(angle) + od.y * cos(angle);
		((t_player *)param)->rot_angle += angle;
	}
	mlx_set_mouse_pos(get_cube()->mlx, cx, (int32_t)(WIN_HEIGHT / 2));
}
