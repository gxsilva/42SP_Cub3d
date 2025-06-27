/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:13:57 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/27 19:06:38 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

//Arguments error
# define INVALID_ARGUMENTS_AMOUNT "Invalid format: $>./cub3d <map_name>.cub"

//Variable erros
# define NULL_POINTER "Null pointer encountered"
# define INVALID_COLOR_FORMAT "Invalid color format"

//Memory errors
# define INVALID_MALLOC "Invalid Malloc"

//Extension error
# define INVALID_EXT "Invalid extension"

//open error
# define INVALID_OPEN "Invalid open"

// Empty map (gnl = NULL)
# define INVALID_EMPTY_MAP "Invalid empty map"

// map doesn´t surround by walls
# define INVALID_WALLS_FORMAT "Invalid walls format"

// Empty line in map
# define INVALID_EMPTY_LINE "Invalid empty line"

// Invalid caracter in map
# define INVALID_CARACTER "Invalid CARACTER"

//file format
# define INVALID_FILE_FORMAT "Invalid file format"
# define INVALID_FILE_CHAR "Invalid type of char in file"

# define INVALID_NO_XPM "Invalid NO xpm file"
# define INVALID_SO_XPM "Invalid SO xpm file"
# define INVALID_WE_XPM "Invalid WE xpm file"
# define INVALID_EA_XPM "Invalid EA xpm file"

# define INVALID_NO_DUPLICATE "Duplicate NO xpm file entry"
# define INVALID_SO_DUPLICATE "Duplicate SO xpm file entry"
# define INVALID_WE_DUPLICATE "Duplicate WE xpm file entry"
# define INVALID_EA_DUPLICATE "Duplicate EA xpm file entry"

# define INVALID_NO_XPM_PATH "Invalid NO xpm path file"
# define INVALID_SO_XPM_PATH "Invalid SO xpm path file"
# define INVALID_WE_XPM_PATH "Invalid WE xpm path file"
# define INVALID_EA_XPM_PATH "Invalid EA xpm path file"

# define INVALID_DUPLICATE_XPM "Duplicate xpm file entry"

# define INVALID_FLOOR_COLOR "Invalid floor color"
# define INVALID_CEILING_COLOR "Invalid ceiling color"

#endif // ERRORS_H
