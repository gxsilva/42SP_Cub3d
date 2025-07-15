/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:20:45 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/14 16:20:46 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	key_press(mlx_key_data_t keydata, t_cube *cube);
void	key_release(mlx_key_data_t keydata, t_cube *cube);
void	update_key_state(mlx_key_data_t keydata, void *param);
void	set_escape_hooks(mlx_key_data_t keydata, void *param);
void	set_hooks(mlx_key_data_t keydata, void *param);

void	set_hooks(mlx_key_data_t keydata, void *param)
{
	update_key_state(keydata, param);
	set_escape_hooks(keydata, param);
	interact_with_door(keydata, get_cube());
}

void	update_key_state(mlx_key_data_t keydata, void *param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	key_press(keydata, cube);
	key_release(keydata, cube);
}

void	set_escape_hooks(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		if (DEBUG_FLAG)
			print_color ("Escape key pressed, exiting", BRIGHT_YELLOW);
		mlx_close_window(((t_cube *)param)->mlx);
	}
}

void	key_press(mlx_key_data_t keydata, t_cube *cube)
{
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_W)
			cube->keys.w = true;
		if (keydata.key == MLX_KEY_S)
			cube->keys.s = true;
		if (keydata.key == MLX_KEY_A)
			cube->keys.a = true;
		if (keydata.key == MLX_KEY_D)
			cube->keys.d = true;
		if (keydata.key == MLX_KEY_LEFT)
			cube->keys.left = true;
		if (keydata.key == MLX_KEY_RIGHT)
			cube->keys.right = true;
	}
}

void	key_release(mlx_key_data_t keydata, t_cube *cube)
{
	if (keydata.action == MLX_RELEASE)
	{
		if (keydata.key == MLX_KEY_W)
			cube->keys.w = false;
		if (keydata.key == MLX_KEY_S)
			cube->keys.s = false;
		if (keydata.key == MLX_KEY_A)
			cube->keys.a = false;
		if (keydata.key == MLX_KEY_D)
			cube->keys.d = false;
		if (keydata.key == MLX_KEY_LEFT)
			cube->keys.left = false;
		if (keydata.key == MLX_KEY_RIGHT)
			cube->keys.right = false;
	}
}
