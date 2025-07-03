/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_debug.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:27:33 by ailbezer          #+#    #+#             */
/*   Updated: 2025/07/03 17:58:16 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	print_ray_struct(t_ray *ray);
void	print_dda_struct(t_dda *dda);

void	print_ray_struct(t_ray *ray)
{
	printf(YELLOW"========== RAY STRUCT =========\n"RESET);
	printf("START_LINE:\t%f\n", ray->camera_x);
	printf("HEIGHT:\t\t%f\n", ray->deltadist_x);
	printf("DELTADIST_Y:\t%f\n", ray->deltadist_y);
	printf("DIR_X:\t\t%f\n", ray->dir_x);
	printf("DIR_Y:\t\t%f\n", ray->dir_y);
	printf("MAP_X:\t\t%d\n", ray->map_x);
	printf("MAP_Y:\t\t%d\n", ray->map_y);
	printf("SIDE:\t\t%d\n", ray->side);
	printf(YELLOW"===============================\n"RESET);
}

void	print_dda_struct(t_dda *dda)
{
	printf(YELLOW"========== DDA STRUCT =========\n"RESET);
	printf("SIDE_DIST_X:\t%f\n", dda->side_dist_x);
	printf("SIDE_DIST_Y:\t%f\n", dda->side_dist_y);
	printf("STEP_X:\t\t%d\n", dda->step_x);
	printf("DIR_X:\t\t%d\n", dda->step_y);
	printf(YELLOW"===============================\n"RESET);
}