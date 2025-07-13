/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 02:42:22 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/13 19:39:20 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	player_pst(void *param);
void	rotate_direction(int turn_direction, t_cube *cube);
void	set_up_down(void *param);
void	set_left_right(void *param);
void	set_arrows_hooks(void *param);

void	player_pst(void *param)
{
	set_up_down(param);
	set_left_right(param);
	set_arrows_hooks(param);
	set_player_plane(get_cube()->player);
}

void	rotate_direction(int turn_direction, t_cube *cube)
{
	cube->player->rot_angle += turn_direction * cube->player->rot_speed;
	cube->player->dir_x = cos(cube->player->rot_angle);
	cube->player->dir_y = sin(cube->player->rot_angle);
}

void	set_up_down(void *param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	if (cube->keys.w)
	{
		if (DEBUG_FLAG)
			print_color("W key pressed", BRIGHT_YELLOW);
		if (wall_collision_player(cube, 'W'))
			return ;
		cube->player->pos_x += calc_pst(cube->player->rot_angle, 0);
		cube->player->pos_y += calc_pst(cube->player->rot_angle, -1);
	}
	else if (cube->keys.s)
	{
		if (DEBUG_FLAG)
			print_color("S key pressed", BRIGHT_YELLOW);
		if (wall_collision_player(cube, 'S'))
			return ;
		cube->player->pos_x -= calc_pst(cube->player->rot_angle, 0);
		cube->player->pos_y -= calc_pst(cube->player->rot_angle, 1);
	}
}

void	set_left_right(void *param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	if (cube->keys.d)
	{
		if (DEBUG_FLAG)
			print_color("D key pressed", BRIGHT_YELLOW);
		if (wall_collision_player(cube, 'D'))
			return ;
		cube->player->pos_x -= calc_pst(cube->player->rot_angle, 1);
		cube->player->pos_y += calc_pst(cube->player->rot_angle, 0);
	}
	else if (cube->keys.a)
	{
		if (DEBUG_FLAG)
			print_color("A key pressed", BRIGHT_YELLOW);
		if (wall_collision_player(cube, 'A'))
			return ;
		cube->player->pos_x += calc_pst(cube->player->rot_angle, -1);
		cube->player->pos_y -= calc_pst(cube->player->rot_angle, 0);
	}
}

void	set_arrows_hooks(void *param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	if (cube->keys.left)
	{
		if (DEBUG_FLAG)
			print_color("Left arrow key pressed", BRIGHT_YELLOW);
		rotate_direction(-1, (t_cube *)param);
	}
	else if (cube->keys.right)
	{
		if (DEBUG_FLAG)
			print_color("Right arrow key pressed", BRIGHT_YELLOW);
		rotate_direction(1, (t_cube *)param);
	}
}
