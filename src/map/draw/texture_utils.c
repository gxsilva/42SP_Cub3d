/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 21:12:39 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/14 20:17:09 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

void	init_struct_texture(t_textures *texture)
{
	texture->north = NULL;
	texture->sky = NULL;
	texture->south = NULL;
	texture->east = NULL;
	texture->west = NULL;
	texture->door = NULL;
	texture->tex = NULL;
	texture->tex_x = 0;
}
