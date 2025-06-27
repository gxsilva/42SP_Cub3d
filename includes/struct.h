/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:05:11 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/26 20:28:35 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#ifndef STRUCT_H
#define STRUCT_H

typedef struct s_map
{
	int		start_map;
	int		height;
	int		width;
	// int		fd;
	char	*name;
	int		**matrix;
} t_map;

typedef struct s_player
{
	int map_pos_x;
	int map_pos_y;
	int dir_x;
	int dir_y;
} t_player;

typedef struct s_cube
{
	t_map		*map;
	t_player	*player;
} t_cube;



#endif //STRUCT_H