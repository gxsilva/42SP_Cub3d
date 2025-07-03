/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   principal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 19:14:07 by ailbezer          #+#    #+#             */
/*   Updated: 2025/07/03 18:30:44 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

void	define_ray_dir(t_ray *ray, t_player *player, int x);
t_dda	*init_dda(t_ray *ray, double pos_x, double pos_y);
t_dda	*dda(t_ray *ray, t_player *player, int **matrix);
void	raycast(t_cube *cube);
void	calc_wall_height(t_ray *ray, t_player *player, mlx_image_t *map, int x, t_dda *dda);


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

// side_dist = distancia inicial ate a primeira linha no eixo x/y 
// step = direção para onde o raio vai ter que andar
t_dda	*init_dda(t_ray *ray, double pos_x, double pos_y)
{
	t_dda	*dda;

	dda = malloc(sizeof(t_dda));
	// ! erro no malloc
	if (ray->dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist_x = (ray->map_x + 1.0 - pos_x) * ray->deltadist_x;
	}
	if (ray->dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist_y = (ray->map_y + 1.0 - pos_y) * ray->deltadist_y;
	}
	return (dda);
}

t_dda	*dda(t_ray *ray, t_player *player, int **matrix)
{
	t_dda	*dda;
	int		hit;

	dda = init_dda(ray, player->pos_x, player->pos_y);
	hit = 0;
	while (hit == 0)
	{
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += ray->deltadist_x;
			ray->map_x += dda->step_x;
			ray->side = 0 ; //hit vertical
		}
		else
		{
			dda->side_dist_y += ray->deltadist_y;
			ray->map_y += dda->step_y;
			ray->side = 1; //hit horizontal
		}
		if (matrix[ray->map_y][ray->map_x] > 0)
			hit = 1;
	}
	// free(dda);
	return (dda);
}

void	calc_wall_height(t_ray *ray, t_player *player, mlx_image_t *map, int x, t_dda *dda)
{
	(void)player;

	double	perp_wall_dist;
	int		line_height;
	
	int		draw_start;
	int		draw_end;
	
	// buffer da imagem
	// uint32_t *buffer = (uint32_t)map->pixels;
	
	if (ray->side == 0)
		perp_wall_dist = (dda->side_dist_x - ray->deltadist_x);
	else
		perp_wall_dist = (dda->side_dist_y - ray->deltadist_y);
	if (perp_wall_dist < 0)
			perp_wall_dist = 0.1;

	// printf("\nMAP_X: %i\n", ray->map_x);
	// printf("MAP_Y: %i\n", ray->map_y);
	// printf("PERP_WALL_DIST: %f\n", perp_wall_dist);
	// printf("===========================================\n");
	line_height = (int)(WIN_HEIGHT / perp_wall_dist);

	// centraliza a parede na vertical da janela
	// draw_start = -(line_height) / 2 + WIN_HEIGHT / 2;
	// draw_end = line_height / 2 + WIN_HEIGHT / 2;
	draw_start = (WIN_HEIGHT - line_height) / 2;
	draw_end = (WIN_HEIGHT + line_height) / 2;

	// corrigir caso o começo ou fim da linha ultrapasse o limite da tela
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= WIN_HEIGHT)
		draw_end = WIN_HEIGHT - 1;

	// desenhar o mapa
	int y = -1;
	while (++y < WIN_HEIGHT)
	{
		if (y < draw_start)
			mlx_put_pixel(map, x, y, GRAY_PX);
		else if (y >= draw_start && y < draw_end)
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
		// 5. Calcular altura da parede
		// 6. Desenhar linha vertical em x com a textura ou cor
		calc_wall_height(ray, cube->player, cube->principal_map, x, ddad);
		// if (DEBUG_FLAG)
		// {
		// 	print_ray_struct(ray);
		// 	print_dda_struct(ddad);
		// }
	}
}