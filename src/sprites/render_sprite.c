/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 21:32:19 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/14 19:17:41 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	check_sprite_hit(t_cube *cube, int *hit)
{
	cube->sprite = false;
	if (cube->ray->map_x >= 0 && cube->ray->map_x < cube->map->width
		&& cube->ray->map_y >= 0 && cube->ray->map_y < cube->map->height)
	{
		if (cube->map->matrix[cube->ray->map_y][cube->ray->map_x] == 5)
		{
			cube->sprite = true;
			*hit = 1;
		}
	}
}

void	draw_set_values(t_sprited *sb, t_cube *cube)
{
	sb->sprite.x = cube->ray->map_x + 0.5 - cube->player->pos_x;
	sb->sprite.y = cube->ray->map_y + 0.5 - cube->player->pos_y;
	sb->inv_det = 1.0 / (cube->player->plane_x * cube->player->dir_y
			- cube->player->dir_x * cube->player->plane_y);
	sb->transform.x = sb->inv_det * (cube->player->dir_y * sb->sprite.x
			- cube->player->dir_x * sb->sprite.y);
	sb->transform.y = sb->inv_det * (-cube->player->plane_y
			* sb->sprite.x + cube->player->plane_x * sb->sprite.y);
	sb->sprite_screen = (int)((WIN_WIDTH / 2)
			* (1 + sb->transform.x / sb->transform.y));
	sb->sprite_d.y = fabs(WIN_HEIGHT / sb->transform.y);
	sb->sprite_d.x = fabs(WIN_HEIGHT / sb->transform.y);
	sb->draw_start.y = -(sb->sprite_d.y) / 2 + WIN_HEIGHT / 2;
}

void	draw_set_condition(t_sprited *sb)
{
	if (sb->draw_start.y < 0)
		sb->draw_start.y = 0;
	sb->draw_end.y = sb->sprite_d.y / 2 + WIN_HEIGHT / 2;
	if (sb->draw_end.y < 0)
		sb->draw_end.y = 0;
	sb->draw_start.x = -(sb->sprite_d.x) / 2 + sb->sprite_screen;
	if (sb->draw_start.x < 0)
		sb->draw_start.x = 0;
	sb->draw_end.x = sb->sprite_d.x / 2 + sb->sprite_screen;
	if (sb->draw_end.x >= WIN_WIDTH)
		sb->draw_end.x = WIN_WIDTH - 2;
}

void	draw_sprites(t_cube *cube, int x)
{
	t_sprited	*sb;
	int			y;
	int			tex_x;

	sb = (t_sprited *) malloc(sizeof(t_sprited));
	if (!sb)
		error_msg(INVALID_MALLOC, BRIGHT_RED, DEBUG_FLAG, 1);
	draw_set_values(sb, cube);
	draw_set_condition(sb);
	if (x >= sb->draw_start.x && x <= sb->draw_end.x && sb->transform.y
		> 0 && sb->transform.y < cube->z_buffer[x])
	{
		cube->textures->tex = cube->sprites->frames[cube->sprites->crr_frame];
		tex_x = (int)((x - sb->draw_start.x)
				* cube->textures->tex->width / sb->sprite_d.x);
		y = sb->draw_start.y;
		while (y++ < sb->draw_end.y)
			draw_texture(cube, x, y, tex_x);
	}
	free(sb);
}

void	render_sprite(void *param)
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
		perform_dda(cube, &check_sprite_hit);
		calc_wall_dist(cube->dda, cube->ray, cube->player);
		calc_wall_height(cube->dda);
		draw_sprites(cube, x);
		free(cube->dda);
		cube->dda = NULL;
	}
	free(cube->ray);
	cube->ray = NULL;
}
