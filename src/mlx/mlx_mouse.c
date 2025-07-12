/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:06:51 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/12 19:37:14 by lsilva-x         ###   ########.fr       */
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

/*
xpos -> x coordinate pst
ypos -> x coordinate pst
last_x -> previous x pst

double sensitivity = 0.002; -> pattern to mouse move speed

delta_x -> the movement based on the last last_x
angle -> based in the movement and sensitivity


old_dir_x -> previous 
*/


/*
enum mouse_key key
	MLX_MOUSE_BUTTON_LEFT	= 0,
	MLX_MOUSE_BUTTON_RIGHT	= 1,
	MLX_MOUSE_BUTTON_MIDDLE	= 2,

enum action
	MLX_RELEASE = 0,
	MLX_PRESS	= 1,
	MLX_REPEAT	= 2,

typedef enum modifier_key
	MLX_SHIFT		= 0x0001,
	MLX_CONTROL		= 0x0002,
	MLX_ALT			= 0x0004,
	MLX_SUPERKEY	= 0x0008,
	MLX_CAPSLOCK	= 0x0010,
	MLX_NUMLOCK		= 0x0020,
*/

// void mouse_callback(enum mouse_key key, enum action action, enum modifier_key mods, void *param)
// {
// 	t_cube  *cube = param;

// 	int32_t  x_i, y_i;
// 	double   xpos, ypos;

// 	(void)ypos;
// 	(void)key;
// 	(void)action;
// 	double   delta_x;
// 	double   angle;
	
// 	t_vec    old_dirplane;

// 	(void)mods;
// 	mlx_get_mouse_pos(cube->mlx, &x_i, &y_i);
// 	printf("Mouse position: x = %d, y = %d\n", x_i, y_i);
// 	xpos = (double)x_i;
// 	ypos = (double)y_i;
// 	if (cube->mouse_lx < 0)
// 		cube->mouse_lx = xpos;
// 	delta_x = xpos - cube->mouse_lx;
// 	cube->mouse_lx = xpos;
// 	// mlx_set_mouse_pos(cube->mlx, WIN_WIDTH / 2, WIN_HEIGHT / 2);
// 	angle = delta_x * MOUSE_SENS;
// 	old_dirplane.x = cube->player->dir_x;
// 	old_dirplane.y = cube->player->plane_x;
// 	cube->player->dir_x = cube->player->dir_x * cos(angle) - cube->player->dir_y * sin(angle);
// 	cube->player->dir_y = old_dirplane.x * sin(angle)  + cube->player->dir_y * cos(angle);
// 	cube->player->plane_x = cube->player->plane_x * cos(angle) - cube->player->plane_y * sin(angle);
// 	cube->player->plane_y = old_dirplane.y * sin(angle) + cube->player->plane_y * cos(angle);
// }
