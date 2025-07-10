/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:56:07 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/10 20:29:30 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

static void	key_press(mlx_key_data_t keydata, t_cube *cube);
static void	key_release(mlx_key_data_t keydata, t_cube *cube);
void		update_key_state(mlx_key_data_t keydata, void *param);

void	interact_with_door(mlx_key_data_t keydata, t_cube *cube)
{
	int		px;
	int		py;
	int		dx;
	int		dy;

	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
	{
		px = (int)cube->player->pos_x;
		py = (int)cube->player->pos_y;
		dx = px + (int)cube->player->dir_x;
		dy = py +(int)cube->player->dir_y;
		if (cube->map->matrix[dy][dx] == 3)
			cube->map->matrix[dy][dx] = 4;
	}
}

static void	key_press(mlx_key_data_t keydata, t_cube *cube)
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

static void	key_release(mlx_key_data_t keydata, t_cube *cube)
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

void	update_key_state(mlx_key_data_t keydata, void *param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	key_press(keydata, cube);
	key_release(keydata, cube);
}
