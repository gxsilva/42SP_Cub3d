/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:13:57 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/25 02:04:52 by lsilva-x         ###   ########.fr       */
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

#endif // ERRORS_HPP