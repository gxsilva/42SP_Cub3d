/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 20:00:35 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/04 20:15:49 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

static double	dda_set_step(double dx, double dy)
{
	if (fabs(dx) > fabs(dy))
		return (fabs(dx));
	return (fabs(dy));
}

void	draw_line_dda(t_vec init, t_vec end, uint32_t color)
{
	int		steps;
	t_vec	inc;
	t_vec	loop;
	t_vec	d;
	int		i;

	i = 0;
	d.x = end.x - init.x;
	d.y = end.y - init.y;
	steps = dda_set_step(d.x, d.y);
	inc.x = d.x / steps;
	inc.y = d.y / steps;
	loop.x = init.x;
	loop.y = init.y;
	while (i <= steps)
	{
		mlx_put_pixel(get_cube()->minimap, (int)loop.x, (int)loop.y, color);
		loop.x += inc.x;
		loop.y += inc.y;
		i++;
	}
}
