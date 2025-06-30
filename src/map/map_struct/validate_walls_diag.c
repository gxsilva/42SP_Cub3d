/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_walls_diag.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 12:38:40 by ailbezer          #+#    #+#             */
/*   Updated: 2025/06/30 14:18:37 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

static bool	is_valid_index(int x, int map_width, int y, int map_height);
void		check_diag_e(int x, int w, int y, int h);
void		check_diag_w(int x, int w, int y, int h);
void		check_diag_n(int x, int w, int y, int h);
void		check_diag_s(int x, int w, int y, int h);

static bool	is_valid_index(int x, int map_width, int y, int map_height)
{
	return (x > 0 && x < map_width && y > 0 && y < map_height);
}

void	check_diag_e(int x, int w, int y, int h)
{
	int	**m;

	m = (get_cube())->map->matrix;
	if ((is_valid_index(x + 1, w, y - 1, h) && m[y - 1][x + 1] != 1
		&& m[y - 1][x + 1] != 2)
			|| (is_valid_index(x + 1, w, y + 1, h) && m[y + 1][x + 1] != 1
			&& m[y + 1][x + 1] != 2))
			error_msg(INVALID_WALLS_FORMAT, BRIGHT_RED, DEBUG_FLAG, 1);
}

void	check_diag_w(int x, int w, int y, int h)
{
	int	**m;

	m = (get_cube())->map->matrix;
	if ((is_valid_index( x -1, w, y - 1, h) && m[y - 1][x - 1] != 1
		&& m[y - 1][x - 1] != 2)
		|| (is_valid_index(x - 1, w, y + 1, h) && m[y + 1][x - 1] != 1
		&& m[y + 1][x - 1] != 2))
			error_msg(INVALID_WALLS_FORMAT, BRIGHT_RED, DEBUG_FLAG, 1);
}

void	check_diag_n(int x, int w, int y, int h)
{
	int	**m;

	m = (get_cube())->map->matrix;
	if ((is_valid_index(x - 1, w, y - 1, h) && m[y - 1][x - 1] != 1
		&& m[y - 1][x - 1] != 2)
		|| (is_valid_index(x + 1, w, y - 1, h) && m[y - 1][x + 1] != 1
		&& m[y - 1][x + 1] != 2))
			error_msg(INVALID_WALLS_FORMAT, BRIGHT_RED, DEBUG_FLAG, 1);
}

void	check_diag_s(int x, int w, int y, int h)
{
	int	**m;

	m = (get_cube())->map->matrix;
	if ((is_valid_index(x - 1, w, y + 1, h) && m[y + 1][x - 1] != 1
		&& m[y + 1][x - 1] != 2)
		|| (is_valid_index(x + 1, w, y + 1, h) && m[y + 1][x + 1] != 1
		&& m[y + 1][x + 1] != 2))
			error_msg(INVALID_WALLS_FORMAT, BRIGHT_RED, DEBUG_FLAG, 1);
}
