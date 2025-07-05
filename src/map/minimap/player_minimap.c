/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 20:00:14 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/05 18:24:07 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

void	draw_player_direction(int cX, int cY)
{
	t_vec	init;
	t_vec	end;

	init.x = cX;
	init.y = cY;
	end.x = init.x + get_cube()->player->dir_x * TILE;
	end.y = init.y + get_cube()->player->dir_y * TILE;
	draw_line_dda(init, end, RED_PX);
}

void	draw_player(mlx_image_t *img, double player_x, double player_y)
{
	int		i;
	int		j;
	t_vec	center;
	t_vec	p;
	int		size;

	center.x = (int)round(player_x * TILE);
	center.y = (int)round(player_y * TILE);
	size = TILE / 4;
	i = -size / 2;
	while (i <= size / 2)
	{
		j = -size / 2;
		while (j <= size / 2)
		{
			p.x = center.x + j;
			p.y = center.y + i;
			mlx_put_pixel(img, p.x, p.y, RED_PX);
			j++;
		}
		i++;
	}
	draw_player_direction(center.x, center.y);
}
