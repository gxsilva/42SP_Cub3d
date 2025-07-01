/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:59:01 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/01 17:55:11 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "header.h"

t_cube		*get_cube(void);

void		init_map(t_cube *cube, char **argv);

//Player functions
t_player	*init_player(int i, int *j, char dir);

//Map functions
void		clean_static(int fd);
void		end_of_map(int fd, char *line);
int			is_empty_line(char *line, int pos);
void		parse_map(t_map *map);
// void		leftovers(int fd);

//Minimap functions
void		draw_minimap(t_cube *cube);

//Map infos
int			width_len(char *line, int fd);
int			get_width(t_map *map);
int			get_height(t_map *map);
int			get_start(char *map_name);
char		*jump_to_map(t_map *map, char *line, int fd);

//Map matrix
void		clear_matrix(t_map *map);
void		alloc_matrix(t_map *map);
void		put_in_matrix(t_map *map, int i, int *j, char *line);
void		fill_matrix(t_map *map);

// Validate walls
void		check_wall_init(char *line, int fd, int i);
void		check_walls(t_map *map);
void		check_diag_e(int x, int w, int y, int h);
void		check_diag_w(int x, int w, int y, int h);
void		check_diag_n(int x, int w, int y, int h);
void		check_diag_s(int x, int w, int y, int h);

//Common functions
void		check_file(t_cube *cube);

//Error
void		error_msg(char *err_str, char *color, int debug_opt, int std_opt);
int			error_stay(char *err_str, char *color);

//Debug functions
void		debug_file_struct(t_file *file);
void		print_map_struct(t_map *map);
void		print_matrix(t_map *map);
void		print_player_struct(void);

//Utils
int			strlen_space(char *line);
char		*sanitize_string(char *line);
void		format_path(char **xpm_path);
void		free_two(void *ptr, void *ptr2);
void		print_color(char *str, char *color);

//File functions
void		check_file(t_cube *cube);
void		init_file_struct(t_cube *cube);
int			fill_file_struct(char *line, t_file *file);
int			verify_file_struct(t_file *file);
void		verify_format_path(t_file *file);

//File functions struct
void		fill_directions(char *line, t_file *file);
void		fill_floor_ceiling(char *line, t_file *file);

//RGB functions
int			count_elements(char **array);
int			rgb_to_int(char *str);

//Xpm verify
int			verify_xpm_extension(t_file *file);
int			verify_coordinates(t_file *file);
int			verify_xpm_path(t_file *file);

//Free functions
void		free_cube(t_cube *cube);
void		free_file(t_file *file);
void		free_map(t_map *map);
void		free_player(t_player *player);
void		free_split(void **matrix);

//MLX functions
void		set_hooks(mlx_key_data_t keydata, void *param);

#endif // FUNCTIONS_H
