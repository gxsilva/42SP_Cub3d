/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 03:04:18 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/14 03:17:07 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

#include <math.h>

// q sono XD
int	ft_random(int min, int max)
{
	double	time;
	int		random;

	time = sin(mlx_get_time()) * 10000.0;
	time = time - (int)time;
	random = (int)(fabs(time) * (max - min + 1)) + min;
	return (random);
}