/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:09:58 by ailbezer          #+#    #+#             */
/*   Updated: 2025/07/04 20:26:47 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

void	init_textures(void);

void	init_textures(void)
{
	t_cube		*cube;

	cube = get_cube();
	cube->textures = malloc(sizeof(t_textures));
	// todo tratar erro malloc
	cube->textures->north = &mlx_load_xpm42(cube->file->no_path)->texture;
	cube->textures->south = &mlx_load_xpm42(cube->file->so_path)->texture;
	cube->textures->east = &mlx_load_xpm42(cube->file->ea_path)->texture;
	cube->textures->west = &mlx_load_xpm42(cube->file->we_path)->texture;
	// todo tratar erro mlx_load_png
}
