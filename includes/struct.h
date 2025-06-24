/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:05:11 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/24 15:44:49 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#ifndef STRUCT_H
#define STRUCT_H

typedef struct s_map
{
	int		height;
	int		width;
	int		fd;
	int		**matrix;
} t_map;

typedef struct s_cube
{
	t_map	*map;
} t_cube;


#endif //STRUCT_H