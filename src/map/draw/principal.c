/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   principal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 19:14:07 by ailbezer          #+#    #+#             */
/*   Updated: 2025/07/03 20:06:44 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

void	draw_3dmap(t_dda *dda, int x, mlx_image_t *map);
void	define_ray_dir(t_ray *ray, t_player *player, int x);
void	raycast(t_cube *cube);

// camera_x = define se a coluna que estamos verificando está mais a esquerda ou
// esquerda da tela.
// dir_x, dir_y = define para qual direção o raio deve ir.
// deltadist = o quanto o raio vai percorrer a cada vez, isso por si ja nos permite verificar
// os indexes da matrix e dizer se estamos batendo ema parede ou não.
// resumindo, permite que o raio se mova exatamente a distancia necessario para ir para
// proximo x ou y na matriz;
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

void	draw_3dmap(t_dda *dda, int x, mlx_image_t *map)
{
	int y;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		if (y < dda->draw_start)
			mlx_put_pixel(map, x, y, GRAY_PX);
		else if (y >= dda->draw_start && y < dda->draw_end)
			mlx_put_pixel(map, x, y, RED_PX);
		else
			mlx_put_pixel(map, x, y, GREEN_PX);
	}
}

// calcular a direção do raio para cada coluna da janela
void	raycast(t_cube *cube)
{
	t_ray *ray;
	int x;
	
	t_dda *ddad;

	ray = malloc(sizeof(t_ray));
	// !erro no malloc
	x = -1;
	while (++x < WIN_WIDTH)
	{
		// 1. Calcular ray_dir com base em x
		define_ray_dir(ray, cube->player, x);
		// 2. Inicializar map_x/y, delta_dist, step, side_dist // 3. Loop DDA
		ddad = dda(ray, cube->player, cube->map->matrix);
		// 4. Calcular distancia perpendicular
		calc_wall_dist(ddad, ray);
		// 5. Calcular altura da parede
		calc_wall_height(ddad);
		// 6. Desenhar linha vertical em x com a textura ou cor
		draw_3dmap(ddad, x, cube->principal_map);
		// if (DEBUG_FLAG)
		// {
		// 	print_ray_struct(ray);
		// 	print_dda_struct(ddad);
		// }
	}
}