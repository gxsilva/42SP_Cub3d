/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:13:57 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/01 01:35:22 by lsilva-x         ###   ########.fr       */
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

// Empty file (gnl = NULL)
# define INVALID_EMPTY_FILE "Invalid empty file"

// Player validate
# define INVALID_PLAYER_COUNT "Invalid number of players"
# define INVALID_PLAYER_DIR "Invalid player direction"

// Map format
# define INVALID_MISSING_MAP "Missing map"
# define INVALID_MISSING_WALL "Missing wall"
# define INVALID_WALLS_FORMAT "map doesn´t surround by walls"
# define INVALID_EMPTY_LINE "Invalid empty line in map"

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

//MLX errors
# define UNABLE_INIT_MLX "Unable to initialize MLX"

#endif // ERRORS_H
