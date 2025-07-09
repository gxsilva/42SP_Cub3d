/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 19:14:07 by ailbezer          #+#    #+#             */
/*   Updated: 2025/07/09 17:28:08 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

void	define_ray_dir(t_ray *ray, t_player *player, int x);
void	raycast(void *param);

// camera_x = define se a coluna que estamos verificando está mais a esquerda
// ou direita da tela.
// dir_x, dir_y = define para qual direção o raio deve ir.
// deltadist = o quanto o raio vai percorrer a cada vez, isso por si ja nos
// permite verificar os indexes da matrix e dizer se estamos batendo ema parede
//  ou não.
// resumindo, permite que o raio se mova exatamente a distancia necessario para
//  ir para proximo x ou y na matriz;
// map_x, map_y é a posição do raio dentro da matrix.
void	define_ray_dir(t_ray *ray, t_player *player, int x)
{
	ray->camera_x = 2 * x / (double)WIN_WIDTH -1;
	ray->dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->deltadist_x = fabs(1 / ray->dir_x);
	ray->deltadist_y = fabs(1 / ray->dir_y);
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
}

// calcular a direção do raio para cada coluna da janela
void	raycast(void *param)
{
	t_cube	*cube;
	int		x;

	cube = (t_cube *)param;
	cube->ray = malloc(sizeof(t_ray));
	if (!cube->ray)
		error_msg(INVALID_MALLOC, BRIGHT_RED, DEBUG_FLAG, 1);
	x = -1;
	while (++x < WIN_WIDTH)
	{
		define_ray_dir(cube->ray, cube->player, x);
		perform_dda(cube, cube->ray, cube->player, cube->map->matrix);
		calc_wall_dist(cube->dda, cube->ray, cube->player);
		calc_wall_height(cube->dda);
		draw_3dmap(cube, x);
		if (DEBUG_FLAG)
		{
			print_ray_struct(cube->ray);
			print_dda_struct(cube->dda);
		}
		free(cube->dda);
		cube->dda = NULL;
	}
	free(cube->ray);
	cube->ray = NULL;
}
