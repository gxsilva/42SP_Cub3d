/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:05:11 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/14 18:14:36 by ailbezer         ###   ########.fr       */
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
	uint32_t	floor;
	uint32_t	ceiling;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
}	t_file;

typedef struct s_vec
{
	double	x;
	double	y;
}	t_vec;

typedef struct s_vec_i
{
	double	x;
	double	y;
}	t_vec_i;

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
	double	perp_wall_dist;
	double	wall_x;
}	t_ray;

typedef struct s_keys
{
	bool	w;
	bool	s;
	bool	a;
	bool	d;
	bool	left;
	bool	right;
}	t_keys;

typedef struct s_textures
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*east;
	mlx_texture_t	*west;
	mlx_texture_t	*door;
	mlx_texture_t	*sky;
	mlx_texture_t	*tex;
	int				tex_x;
}	t_textures;

# ifndef WIN_WIDTH
#  define WIN_WIDTH 1280
# endif

typedef struct s_cube
{
	t_map		*map;
	t_player	*player;
	t_file		*file;
	t_keys		keys;
	t_ray		*ray;
	t_dda		*dda;
	bool		door;
	double		z_buffer[WIN_WIDTH];
	mlx_t		*mlx;
	mlx_image_t	*minimap;
	mlx_image_t	*principal_map;
	mlx_image_t	*doors;
	t_textures	*textures;
	double		elapsed_t;
	double		mouse_lx; //mouse last x pst
	double		last_t;
}	t_cube;

#endif //STRUCT_H