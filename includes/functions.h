/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:59:01 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/14 19:33:48 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "header.h"

t_cube		*get_cube(void);

//Initial functions
void		init_map(t_cube *cube, char **argv);
void		init_cube(t_cube *cube, char **argv);
void		init_mlx(t_cube *cube);
void		check_map(char **argv);
void		cube_loop(t_cube *cube);

//Sprites
void		init_sprites(t_cube *cube);
void		render_sprite(void *param);
void		update_sprites(t_cube *cube);

// Draw_utils
void		draw_sky(t_cube *cube, int y, int x);
void		draw_doors(t_cube *cube, int x);
void		draw_3dmap(t_cube *cube, int x);

//Mouse bonus
void		mouse_loop_hook(void *param);
void		init_cube(t_cube *cube, char **argv);
void		init_mlx(t_cube *cube);
void		check_map(char **argv);
void		cube_loop(t_cube *cube);

//Mouse bonus
void		mouse_loop_hook(void *param);

// raycast
void		define_ray_dir(t_ray *ray, t_player *player, int x);
void		init_dda(t_cube *cube, t_ray *ray, double pos_x, double pos_y);
void		perform_dda(t_cube *cube,
				void (*check_hit)(t_cube *cube, int *hit));
void		raycast(void *param);
void		calc_wall_dist(t_dda *dda, t_ray *ray, t_player *player);
void		calc_wall_height(t_dda *dda);
void		check_hit(t_cube *cube, int *hit);

// Textures
void		render_doors(void *param);
void		init_textures(t_cube *cube);
void		init_struct_texture(t_textures *texture);
void		tex_pixel_to_image(t_cube *cube, int x);
void		draw_texture(t_cube *cube, int x, int y, int tex_x);
int			get_tex_x(t_cube *cube);
uint32_t	get_tex_color(int index, mlx_texture_t *tex);

//Player functions
t_player	*init_player(int i, int *j, char dir);
void		draw_player(mlx_image_t *img, double player_x, double player_y);
int			wall_collision_player(t_cube *cube, int direction);
double		calc_pst(double rot_angle, int opt);
void		draw_line_dda(t_vec init, t_vec end, uint32_t color);
void		set_player_plane(t_player *player);
void		player_pst(void *param);
void		set_arrows_hooks(void *param);
void		rotate_direction(int turn_direction, t_cube *cube);

//Player elapsed movement
void		track_elapsed_time(void *param);

//Player state functions
void		update_key_state(mlx_key_data_t keydata, void *param);
void		key_press(mlx_key_data_t keydata, t_cube *cube);
void		key_release(mlx_key_data_t keydata, t_cube *cube);
void		player_pst(void *param);
void		set_arrows_hooks(void *param);
void		rotate_direction(int turn_direction, t_cube *cube);

//Player state functions
void		update_key_state(mlx_key_data_t keydata, void *param);
void		key_press(mlx_key_data_t keydata, t_cube *cube);
void		key_release(mlx_key_data_t keydata, t_cube *cube);

//Map functions
void		clean_static(int fd);
void		end_of_map(int fd, char *line);
int			is_empty_line(char *line, int pos);
void		parse_map(t_map *map);

//Minimap functions
void		render_minimap(void *param);
void		render_minimap(void *param);
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
void		print_ray_struct(t_ray *ray);
void		print_dda_struct(t_dda *dda);

//Utils
int			strlen_space(char *line);
char		*sanitize_string(char *line);
void		format_path(char **png_path);
void		free_two(void *ptr, void *ptr2);
int			ft_random(int min, int max);
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
uint32_t	rgba_to_int(char *str);

//png verify
int			verify_png_extension(t_file *file);
int			verify_coordinates(t_file *file);
int			verify_png_path(t_file *file);

//Free functions
void		free_cube(t_cube *cube);
void		free_file(t_file *file);
void		free_map(t_map *map);
void		free_textures(t_textures *textures);
void		free_textures(t_textures *textures);
void		free_player(t_player *player);
void		free_split(void **matrix);

//MLX functions
void		set_hooks(mlx_key_data_t keydata, void *param);
void		set_left_right(void *param);
void		set_up_down(void *param);

//MLX key hook functions
void		update_key_state(mlx_key_data_t keydata, void *param);
void		interact_with_door(mlx_key_data_t keydata, t_cube *cube);

#endif // FUNCTIONS_H
