/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:05:11 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/03 19:11:00 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "header.h"

/*
 ░▒▓██████▓▒░       ░▒▓█▓▒░░▒▓█▓▒░      ░▒▓███████▓▒░       ░▒▓████████▓▒░      ░▒▓███████▓▒░  
░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░             ░▒▓█▓▒░░▒▓█▓▒░ 
░▒▓█▓▒░             ░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░             ░▒▓█▓▒░░▒▓█▓▒░ 
░▒▓█▓▒░             ░▒▓█▓▒░░▒▓█▓▒░      ░▒▓███████▓▒░       ░▒▓██████▓▒░        ░▒▓█▓▒░░▒▓█▓▒░ 
░▒▓█▓▒░             ░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░             ░▒▓█▓▒░░▒▓█▓▒░ 
░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░             ░▒▓█▓▒░░▒▓█▓▒░ 
 ░▒▓██████▓▒░        ░▒▓██████▓▒░       ░▒▓███████▓▒░       ░▒▓████████▓▒░      ░▒▓███████▓▒░  
*/

typedef struct s_map
{
	int		start_map;
	int		height;
	int		width;
	char	*name;
	int		fd;
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

typedef struct s_vec
{
	double	x;
	double	y;
} t_vec;

typedef struct s_player
{
	//pos_x	pos_y
	t_vec	pos;

	//dir_x dir_y
	t_vec	dir;
	
	//plane_x plane_y
	t_vec	plane;
	
	double	rot_angle;
	
	double	rot_speed;
	double	move_speed;
}	t_player;

typedef struct s_cube
{
	t_map		*map;
	t_player	*player;
	t_file		*file;
	mlx_t		*mlx;
	mlx_image_t	*minimap;
}	t_cube;

#endif //STRUCT_H