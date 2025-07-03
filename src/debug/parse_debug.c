/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:11:37 by ailbezer          #+#    #+#             */
/*   Updated: 2025/07/03 14:38:47 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	print_map_struct(t_map *map);
void	print_matrix(t_map *map);
void	print_player_struct(void);

void	print_map_struct(t_map *map)
{
	printf(YELLOW"========== MAP STRUCT =========\n"RESET);
	printf("START_LINE:\t%d\n", map->start_map);
	printf("HEIGHT:\t\t%d\n", map->height);
	printf("WIDTH:\t\t%d\n", map->width);
	printf(YELLOW"===============================\n"RESET);
}

void	print_matrix(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	printf(YELLOW"========== MATRIX =========\n"RESET);
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->matrix[i][j] == 2)
				printf(RED"%d"RESET, map->matrix[i][j]);
			else if (map->matrix[i][j] == 1)
				printf(GREEN"%d"RESET, map->matrix[i][j]);
			if (map->matrix[i][j] == 0)
				printf(BLUE"%d"RESET, map->matrix[i][j]);
		}
		printf("\n");
	}
	printf(YELLOW"===============================\n"RESET);
}

void	print_player_struct(void)
{
	t_player	*player;

	player = get_cube()->player;
	printf(YELLOW"=========== PLAYER ============\n"RESET);
	printf("POS_X: %f\n", player->pos_x);
	printf("POS_Y: %f\n", player->pos_y);
	printf("DIR_X: %d\n", player->dir_x);
	printf("DIR_Y: %d\n", player->dir_y);
	printf("PLANE_X: %f\n", player->plane_x);
	printf("PLANE_Y: %f\n", player->plane_y);
	printf(YELLOW"===============================\n"RESET);
}
