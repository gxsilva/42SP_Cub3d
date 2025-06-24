/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:13:57 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/24 16:50:40 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_HPP
#define ERRORS_HPP

//Arguments error
#define INVALID_ARGUMENTS_AMOUNT BRIGHT_RED"Invalid format: $>./cub3d <map_name>.cub"RESET

//Memory errors
#define INVALID_MALLOC "Invalid Malloc"

//Extension error
#define INVALID_EXT BRIGHT_RED"Invalid extension"RESET

//open error
#define INVALID_OPEN BRIGHT_RED"Invalid open"RESET
#endif // ERRORS_HPP