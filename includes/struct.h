/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:05:11 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/08 01:22:03 by lsilva-x         ###   ########.fr       */
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
}	t_vec;

typedef struct s_player
{
	double	dir_x;
	double	dir_y;
	double	pos_x;
	double	pos_y;
	double	plane_x;
	double	plane_y;
	double	rot_angle;
	double	rot_speed;
	double	move_speed;
}	t_player;

typedef struct s_dda
{
	int		step_x;
	int		step_y;
	double	side_dist_y;
	double	side_dist_x;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_dda;

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	double	deltadist_x;
	double	deltadist_y;
	int		map_x;
	int		map_y;
	int		side;
}	t_ray;


typedef struct s1_texture
{
	mlx_image_t	*img_ptr;
	int			width;
	int			height;
}	t_texture;

typedef struct s_walls
{
	t_texture	*no_data;
	t_texture	*so_data;
	t_texture	*we_data;
	t_texture	*ea_data;
} t_walls;

typedef struct s_cube
{
	t_map		*map;
	t_walls		*walls;
	t_player	*player;
	t_file		*file;
	t_ray		*ray;
	mlx_t		*mlx;
	mlx_image_t	*minimap;
	mlx_image_t	*principal_map;
}	t_cube;

#endif //STRUCT_H