/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:05:11 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/26 17:21:42 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "header.h"

typedef struct s_map
{
	int		height;
	int		width;
	int		fd;
	int		**matrix;
}	t_map;

typedef struct s_file
{
	int		floor;
	int		ceiling;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
}	t_file;

typedef struct s_cube
{
	t_map	*map;
	t_file	*file;
}	t_cube;

#endif //STRUCT_H