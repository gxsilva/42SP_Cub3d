/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:56:07 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/10 21:28:54 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

static void	key_press(mlx_key_data_t keydata, t_cube *cube);
static void	key_release(mlx_key_data_t keydata, t_cube *cube);
void		update_key_state(mlx_key_data_t keydata, void *param);
void	interact_with_door(mlx_key_data_t keydata, t_cube *cube)
{
	int px, py;
	int dx[4] = { 1, -1, 0, 0 }; // direita, esquerda, nada, nada
	int dy[4] = { 0, 0, 1, -1 }; // nada, nada, baixo, cima
	int i;
	int tx, ty;

	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
	{
		px = (int)floor(cube->player->pos_x);
		py = (int)floor(cube->player->pos_y);

		for (i = 0; i < 4; i++)
		{
			tx = px + dx[i];
			ty = py + dy[i];

			if (ty >= 0 && ty < cube->map->height &&
				tx >= 0 && tx < cube->map->width)
			{
				int cell = cube->map->matrix[ty][tx];

				if (cell == 3) // porta fechada
				{
					cube->map->matrix[ty][tx] = 4; // abre
					printf("Abrindo porta em [%d][%d]\n", ty, tx);
					return;
				}
				else if (cell == 4) // porta aberta
				{
					cube->map->matrix[ty][tx] = 3; // fecha
					printf("Fechando porta em [%d][%d]\n", ty, tx);
					return;
				}
			}
		}
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
