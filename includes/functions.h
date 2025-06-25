/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:59:01 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/24 20:57:46 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

# include "header.h"

void	init_map(t_cube *cube, char **argv);
void	error_msg (char *err_str, int debug_opt, int std_opt);
void	check_file_origin(t_cube *cube);

//Debug functions
void	debug_file_struct(t_file *file);

//Utils
int		strlen_space(char *line);

#endif // FUNCTIONS_HPP