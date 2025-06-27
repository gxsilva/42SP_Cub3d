/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:05:11 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/27 19:25:38 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "header.h"

typedef struct s_map
{
	int		start_map;
	int		height;
	int		width;
	char	*name;
	int		**matrix;
}	t_map;

typedef struct s_file
{
	int		floor;
	int		ceiling;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
}	t_file;

typedef struct s_player
{
	int		map_pos_x;
	int		map_pos_y;
	int		dir_x;
	int		dir_y;
}	t_player;

typedef struct s_cube
{
	t_map		*map;
	t_player	*player;
	t_file		*file;
}	t_cube;

#endif //STRUCT_H