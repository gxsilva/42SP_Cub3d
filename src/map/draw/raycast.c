/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 19:14:07 by ailbezer          #+#    #+#             */
/*   Updated: 2025/07/12 07:59:08 by ailbezer         ###   ########.fr       */
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

void	clear_image(mlx_image_t *img)
{
	for (uint32_t y = 0; y < img->height; ++y)
		for (uint32_t x = 0; x < img->width; ++x)
			mlx_put_pixel(img, x, y, 0x00000000); // preto opaco ou transparente: 0x00000000
}

// bool	is_pixel_transparent(mlx_texture_t *tex, int tex_x, int tex_y)
// {
// 	int	index;
	
// 	index = (tex_y * tex->width + tex_x) * 4;
// 	return (tex->pixels[index + 3] == 0);
// }

// // testando
// void	cast_until_wall(t_cube *cube, int x)
// {
// 	t_ray		*ray = cube->ray;
// 	t_dda		*dda = cube->dda;
// 	int			hit = 0;
// 	// int			tex_x, tex_y;

// 	// salta a porta: continue DDA
// 	while (!hit)
// 	{
// 		if (dda->side_dist_x < dda->side_dist_y)
// 		{
// 			dda->side_dist_x += ray->deltadist_x;
// 			ray->map_x += dda->step_x;
// 			ray->side = 0;
// 		}
// 		else
// 		{
// 			dda->side_dist_y += ray->deltadist_y;
// 			ray->map_y += dda->step_y;
// 			ray->side = 1;
// 		}
// 		if (cube->map->matrix[ray->map_y][ray->map_x] > 0 &&
// 			cube->map->matrix[ray->map_y][ray->map_x] < 3)
// 			hit = 1;
// 	}
// 	// (void)x;
// 	// desenha parede que está atrás da porta
// 	calc_wall_dist(dda, ray, cube->player);
// 	calc_wall_height(dda);
// 	draw_3dmap(cube, x, 1);
// }




uint32_t	get_tex_colorss(int index, mlx_texture_t *tex)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;

	r = tex->pixels[index + 0];
	g = tex->pixels[index + 1];
	b = tex->pixels[index + 2];
	a = tex->pixels[index + 3];
	return ((a << 24) | (r << 16) | (g << 8) | b);
}


bool	is_horizontal_door(t_cube *cube, int map_x, int map_y)
{
	if (map_x > 0 && map_x < cube->map->width && map_y > 0 && map_y < cube->map->height)
	{
		if (map_x > 0 && cube->map->matrix[map_y][map_x - 1] == 1)
			return (true);
		if (map_x < cube->map->width - 1 && cube->map->matrix[map_y][map_x + 1] == 1)
			return (true);
	}
	return (false);
}

void draw_doors(t_cube *cube, int x)
{

	bool is_horizontal;
	is_horizontal = is_horizontal_door(cube, cube->ray->map_x, cube->ray->map_y);

	if (cube->ray->perp_wall_dist > cube->z_buffer[x])
		return ;

	if ((is_horizontal && cube->ray->side != 1) || (!is_horizontal && cube->ray->side != 0))
		return ;

	if (cube->door)
		cube->textures->tex = cube->textures->door;
	else
		return ;
	int	tex_x;
	int	y;

	tex_x = (int)(cube->ray->wall_x * cube->textures->tex->width);
	if ((cube->ray->side == 0 && cube->ray->dir_x > 0)
		|| (cube->ray->side == 1 && cube->ray->dir_y < 0))
		tex_x = cube->textures->tex->width - tex_x - 1;
	y = -1;
	while (++y < WIN_HEIGHT)
	{
		if (y >= cube->dda->draw_start && y < cube->dda->draw_end)
		{
			uint32_t	color;
			int			tex_y;
			int			index;

			tex_y = ((y - cube->dda->draw_start) * cube->textures->tex->height)
				/ (cube->dda->draw_end - cube->dda->draw_start);
			index = (tex_y * cube->textures->tex->width + tex_x) * 4;
			uint8_t a = cube->textures->tex->pixels[index + 3];
			if (a == 0)
				continue;
			color = get_tex_colorss(index, cube->textures->tex);
			mlx_put_pixel(cube->principal_map, x, y, color);
		}
	}
}

static void	new_check_hit(t_cube *cube, t_ray *ray, int **matrix, int *hit)
{
	cube->door = false;
	if (ray->map_x >= 0 && ray->map_x < cube->map->width &&
		ray->map_y >= 0 && ray->map_y < cube->map->height)
	{
		if (matrix[ray->map_y][ray->map_x] == 3)
		{
			cube->door = true;
			*hit = 1;
		}
	}
}

void	new_perform_dda(t_cube *cube, t_ray *ray, t_player *player, int **matrix)
{
	int		hit;

	init_dda(cube, ray, player->pos_x, player->pos_y);
	hit = 0;
	while (hit == 0 && (ray->map_x >= 0 && ray->map_x < cube->map->width &&
		ray->map_y >= 0 && ray->map_y < cube->map->height))
	{
		if (cube->dda->side_dist_x < cube->dda->side_dist_y)
		{
			cube->dda->side_dist_x += ray->deltadist_x;
			ray->map_x += cube->dda->step_x;
			ray->side = 0 ;
		}
		else
		{
			cube->dda->side_dist_y += ray->deltadist_y;
			ray->map_y += cube->dda->step_y;
			ray->side = 1;
		}
		new_check_hit(cube, ray, matrix, &hit);
	}
}

void new_ray(void *param)
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
		new_perform_dda(cube, cube->ray, cube->player, cube->map->matrix);
		calc_wall_dist(cube->dda, cube->ray, cube->player);
		calc_wall_height(cube->dda);
		// cube->z_buuffer[x] = cube->ray->perp_wall_dist;
		draw_doors(cube, x);
		free(cube->dda);
		cube->dda = NULL;
	}
	free(cube->ray);
	cube->ray = NULL;
}

// ! todo sapoha quase funcionando, mas preciso que os dois sejam desenhados juntos para um não sobreescrever o outrp
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
		cube->z_buffer[x] = cube->ray->perp_wall_dist;
		draw_3dmap(cube, x, 0);
		free(cube->dda);
		cube->dda = NULL;
	}
	free(cube->ray);
	cube->ray = NULL;
}
