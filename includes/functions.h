/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:59:01 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/24 16:05:20 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

# include "header.h"

void	init_map(t_cube *cube);
void	error_msg (char *err_str, int debug_opt, int std_opt);

#endif // FUNCTIONS_HPP