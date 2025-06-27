/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:59:01 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/27 17:59:25 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "header.h"


t_cube	*get_cube(void);

void	init_map(t_cube *cube);

void	leftovers(int fd);
//========= map/parse_map =========
void 	parse_map(t_map *map);

//Common functions
void	check_file(t_cube *cube);

//Error
void	error_msg(char *err_str, char *color, int debug_opt, int std_opt);
int		error_stay(char *err_str);

//Debug functions
void	debug_file_struct(t_file *file);

//Utils
int		strlen_space(char *line);
char	*sanitize_string(char *line);
void	format_path(char **xpm_path);
void	print_color(char *str, char *color);

//File functions
void	check_file(t_cube *cube);
void	init_file_struct(t_cube *cube);
int		fill_file_struct(char *line, t_file *file);
int		verify_file_struct(t_file *file);
void	verify_format_path(t_file *file);

//File functions struct
void	fill_directions(char *line, t_file *file);
void	fill_floor_ceiling(char *line, t_file *file);

//RGB functions
int		count_elements(char **array);
int		rgb_to_int(char *str);

//Xpm verify
int		verify_xpm_extension(t_file *file);
int		verify_coordinates(t_file *file);
int		verify_xpm_path(t_file *file);

//Free functions
void	free_split(void **matrix);
void	free_file(t_file *file);
// void	free_map(t_map *map);

#endif // FUNCTIONS_H
