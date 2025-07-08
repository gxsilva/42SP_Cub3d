/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 02:01:17 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/08 02:02:14 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

static void debug_texture(t_texture *texture, const char *name);
void debug_walls(t_walls *walls);

static void debug_texture(t_texture *texture, const char *name)
{
	if (texture == NULL)
	{
		printf("Texture %s is NULL\n", name);
		return;
	}
	printf("Texture %s:\n", name);
	printf("  Image Pointer: %p\n", texture->img_ptr);
	printf("  Width: %d\n", texture->width);
	printf("  Height: %d\n", texture->height);
}

void debug_walls(t_walls *walls)
{
	if (walls == NULL)
	{
		printf("Walls structure is NULL\n");
		return;
	}
	debug_texture(walls->no_data, "North");
	debug_texture(walls->so_data, "South");
	debug_texture(walls->we_data, "West");
	debug_texture(walls->ea_data, "East");
}