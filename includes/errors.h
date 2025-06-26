/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:13:57 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/26 15:07:36 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_HPP
#define ERRORS_HPP

//Arguments error
#define INVALID_ARGUMENTS_AMOUNT BRIGHT_RED"Invalid format: $>./cub3d <map_name>.cub"RESET

//Variable erros
#define NULL_POINTER BRIGHT_RED"Null pointer encountered"RESET
#define INVALID_COLOR_FORMAT BRIGHT_RED"Invalid color format"RESET

//Memory errors
#define INVALID_MALLOC "Invalid Malloc"

//Extension error
#define INVALID_EXT BRIGHT_RED"Invalid extension"RESET

//open error
#define INVALID_OPEN BRIGHT_RED"Invalid open"RESET

//file format
#define INVALID_FILE_FORMAT BRIGHT_RED"Invalid file format"RESET
#define INVALID_FILE_CHAR BRIGHT_RED"Invalid type of char in file"RESET

#define INVALID_NO_XPM BRIGHT_RED"Invalid NO xpm file"RESET
#define INVALID_SO_XPM BRIGHT_RED"Invalid SO xpm file"RESET
#define INVALID_WE_XPM BRIGHT_RED"Invalid WE xpm file"RESET
#define INVALID_EA_XPM BRIGHT_RED"Invalid EA xpm file"RESET

#define INVALID_NO_DUPLICATE BRIGHT_RED"Duplicate NO xpm file entry"RESET
#define INVALID_SO_DUPLICATE BRIGHT_RED"Duplicate SO xpm file entry"RESET
#define INVALID_WE_DUPLICATE BRIGHT_RED"Duplicate WE xpm file entry"RESET
#define INVALID_EA_DUPLICATE BRIGHT_RED"Duplicate EA xpm file entry"RESET


#define INVALID_NO_XPM_PATH BRIGHT_RED"Invalid NO xpm path file"RESET
#define INVALID_SO_XPM_PATH BRIGHT_RED"Invalid SO xpm path file"RESET
#define INVALID_WE_XPM_PATH BRIGHT_RED"Invalid WE xpm path file"RESET
#define INVALID_EA_XPM_PATH BRIGHT_RED"Invalid EA xpm path file"RESET

#define INVALID_DUPLICATE_XPM BRIGHT_RED"Duplicate xpm file entry"RESET

#define INVALID_FLOOR_COLOR BRIGHT_RED"Invalid floor color"RESET
#define INVALID_CEILING_COLOR BRIGHT_RED"Invalid ceiling color"RESET

#endif // ERRORS_HPP