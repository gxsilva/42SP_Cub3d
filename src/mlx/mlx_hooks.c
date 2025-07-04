/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 02:42:22 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/04 15:05:10 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

/*
░▒▓██████████████▓▒░       ░▒▓█▓▒░             ░▒▓█▓▒░░▒▓█▓▒░ 
░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░             ░▒▓█▓▒░░▒▓█▓▒░ 
░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░             ░▒▓█▓▒░░▒▓█▓▒░ 
░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░              ░▒▓██████▓▒░  
░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░             ░▒▓█▓▒░░▒▓█▓▒░ 
░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░             ░▒▓█▓▒░░▒▓█▓▒░ 
░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░      ░▒▓████████▓▒░      ░▒▓█▓▒░░▒▓█▓▒░ 
*/

void		set_hooks(mlx_key_data_t keydata, void *param);
static void	set_escape_hooks(mlx_key_data_t keydata, void *param);
static void	set_keys_hooks(mlx_key_data_t keydata, void *param);
static void	set_keys_hooks_node(mlx_key_data_t keydata, void *param);
static void	set_arrows_hooks(mlx_key_data_t keydata, void *param);

void	set_hooks(mlx_key_data_t keydata, void *param)
{
	set_escape_hooks(keydata, param);
	set_keys_hooks(keydata, param);
	set_arrows_hooks(keydata, param);
}

static void	set_escape_hooks(mlx_key_data_t keydata, void *param)
{
	(void)param; //!TMP Remove
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		if (DEBUG_FLAG)
			print_color ("Escape key pressed, exiting", BRIGHT_YELLOW);
		mlx_close_window(get_cube()->mlx);
	}
}

double	calc_pst(double	rot_angle, int opt)
{
	if (opt == 0)
		return ((cos(rot_angle) * PLAYER_SPEED));
	else
		return ((sin(rot_angle) * PLAYER_SPEED));
}

static void	set_keys_hooks(mlx_key_data_t keydata, void *param)
{
	(void)param; //!TMP Remove
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
	{
		if (DEBUG_FLAG)
			print_color("W key pressed", BRIGHT_YELLOW);
		get_cube()->player->pos.x += calc_pst(get_cube()->player->rot_angle, 0);
		get_cube()->player->pos.y += calc_pst(get_cube()->player->rot_angle, 1);
	}
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
	{
		if (DEBUG_FLAG)
			print_color("A key pressed", BRIGHT_YELLOW);
		get_cube()->player->pos.x += calc_pst(get_cube()->player->rot_angle, 1);
		get_cube()->player->pos.y -= calc_pst(get_cube()->player->rot_angle, 0);
	}
	set_keys_hooks_node(keydata, param);
}

static void	set_keys_hooks_node(mlx_key_data_t keydata, void *param)
{
	(void)param; //!TMP Remove
	if (keydata.key == MLX_KEY_S && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
	{
		if (DEBUG_FLAG)
			print_color("S key pressed", BRIGHT_YELLOW);
		get_cube()->player->pos.x -= calc_pst(get_cube()->player->rot_angle, 0);
		get_cube()->player->pos.y -= calc_pst(get_cube()->player->rot_angle, 1);
	}
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
	{
		if (DEBUG_FLAG)
			print_color("D key pressed", BRIGHT_YELLOW);
		get_cube()->player->pos.x -= calc_pst(get_cube()->player->rot_angle, 1);
		get_cube()->player->pos.y += calc_pst(get_cube()->player->rot_angle, 0);
	}
}

static void	set_arrows_hooks(mlx_key_data_t keydata, void *param)
{
	(void)param; //!TMP Remove
	if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
	{
		if (DEBUG_FLAG)
			print_color("Left arrow key pressed", BRIGHT_YELLOW);
		//TODO action to Left arrow key
	}
	else if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
	{
		if (DEBUG_FLAG)
			print_color("Right arrow key pressed", BRIGHT_YELLOW);
		//TODO action to Right arrow key
	}
}
