/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 02:42:22 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/05 19:32:29 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void		set_hooks(mlx_key_data_t keydata, void *param);
static void	set_escape_hooks(mlx_key_data_t keydata, void *param);
static void	set_keys_hooks(mlx_key_data_t keydata, void *param);
static void	set_arrows_hooks(mlx_key_data_t keydata, void *param);
static void	rotate_direction(int turn_direction, t_cube *cube);

void	set_hooks(mlx_key_data_t keydata, void *param)
{
	set_escape_hooks(keydata, param);
	set_keys_hooks(keydata, param);
	set_arrows_hooks(keydata, param);
	set_player_plane(get_cube()->player);
}

static void	set_escape_hooks(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		if (DEBUG_FLAG)
			print_color ("Escape key pressed, exiting", BRIGHT_YELLOW);
		mlx_close_window(((t_cube *)param)->mlx);
	}
}

static void	set_keys_hooks(mlx_key_data_t keydata, void *param)
{
	set_up_down(keydata, param);
	set_left_right(keydata, param);
}

static void	set_arrows_hooks(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
	{
		if (DEBUG_FLAG)
			print_color("Left arrow key pressed", BRIGHT_YELLOW);
		rotate_direction(-1, (t_cube *)param);
	}
	else if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
	{
		if (DEBUG_FLAG)
			print_color("Right arrow key pressed", BRIGHT_YELLOW);
		rotate_direction(1, (t_cube *)param);
	}
}

static void	rotate_direction(int turn_direction, t_cube *cube)
{
	cube->player->rot_angle += turn_direction * cube->player->rot_speed;
	cube->player->dir_x = cos(cube->player->rot_angle);
	cube->player->dir_y = sin(cube->player->rot_angle);
}
