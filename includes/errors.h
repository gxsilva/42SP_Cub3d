/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:13:57 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/25 15:08:42 by ailbezer         ###   ########.fr       */
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

// Empty map (gnl = NULL)
#define INVALID_EMPTY_MAP BRIGHT_RED"Invalid empty map"RESET

 // map doesn´t surround by walls
#define INVALID_WALLS_FORMAT BRIGHT_RED"Invalid walls format"RESET

// Empty line in map
#define INVALID_EMPTY_LINE BRIGHT_RED"Invalid empty line"RESET

// Invalid caracter in map
#define INVALID_CARACTER BRIGHT_RED"Invalid CARACTER"RESET

#endif // ERRORS_HPP