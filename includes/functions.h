/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:59:01 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/26 20:02:46 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

# include "header.h"

t_cube	*get_cube(void);

void	init_map(t_cube *cube, char **argv);

void	error_msg (char *err_str, int debug_opt, int std_opt);

void	leftovers(int fd);
//========= map/parse_map =========
void 	parse_map(t_map *map);

#endif // FUNCTIONS_HPP