/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 21:21:35 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/14 16:18:51 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	load_sprites(t_sprite *sprites)
{
	sprites->frames[0] = mlx_load_png(SPRITE_01);
	if (!sprites->frames[0])
		error_msg(FAILED_LOAD_PNG, BRIGHT_RED, DEBUG_FLAG, 1);
	sprites->frames[1] = mlx_load_png(SPRITE_02);
	if (!sprites->frames[1])
		error_msg(FAILED_LOAD_PNG, BRIGHT_RED, DEBUG_FLAG, 1);
	sprites->frames[2] = mlx_load_png(SPRITE_03);
	if (!sprites->frames[2])
		error_msg(FAILED_LOAD_PNG, BRIGHT_RED, DEBUG_FLAG, 1);
	sprites->frames[3] = mlx_load_png(SPRITE_04);
	if (!sprites->frames[3])
		error_msg(FAILED_LOAD_PNG, BRIGHT_RED, DEBUG_FLAG, 1);
	sprites->frames[4] = mlx_load_png(SPRITE_05);
	if (!sprites->frames[4])
		error_msg(FAILED_LOAD_PNG, BRIGHT_RED, DEBUG_FLAG, 1);
}

void	init_sprite_struct(t_sprite *sprites)
{
	sprites->sprite_cnt = SPRITE_CNT;
	sprites->frames = (mlx_texture_t **)malloc(sizeof(mlx_texture_t *)
			* SPRITE_CNT);
	if (!sprites->frames)
		error_msg(INVALID_MALLOC, BRIGHT_RED, DEBUG_FLAG, 1);
	sprites->sprite_speed = 0.5;
	sprites->sprite_timer = 0;
	sprites->crr_frame = 0;
	sprites->refresh_time = 0;
}

void	update_sprites(t_cube *cube)
{
	t_sprite	*sprite;

	sprite = (cube->sprites);
	sprite->sprite_timer += cube->elapsed_t;
	if (sprite->sprite_timer >= sprite->sprite_speed)
	{
		sprite->sprite_timer -= sprite->sprite_speed;
		sprite->crr_frame = (sprite->crr_frame + 1) % sprite->sprite_cnt;
	}
}

void	init_sprites(t_cube *cube)
{
	cube->sprites = (t_sprite *)malloc(sizeof(t_sprite));
	if (!cube->sprites)
		error_msg(INVALID_MALLOC, BRIGHT_RED, DEBUG_FLAG, 1);
	init_sprite_struct(cube->sprites);
	load_sprites (cube->sprites);
}
