/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:09:58 by ailbezer          #+#    #+#             */
/*   Updated: 2025/07/07 19:47:27 by ailbezer         ###   ########.fr       */
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
	if (access("textures/simonkraft/respawn_anchor_side0.xpm42", F_OK) == -1)
		perror("Arquivo não encontrado:");
	else
		puts("Arquivo encontrado!");
	// cube->textures->north_xpm = mlx_load_xpm42(cube->file->no_path);
	cube->textures->north_xpm = mlx_load_xpm42("./textures/simonkraft/respawn_anchor_side0.xpm42");
	cube->textures->south_xpm = mlx_load_xpm42(cube->file->so_path);
	cube->textures->east_xpm = mlx_load_xpm42(cube->file->ea_path);
	cube->textures->west_xpm = mlx_load_xpm42(cube->file->we_path);

	cube->textures->north = &cube->textures->north_xpm->texture;
	cube->textures->west = &cube->textures->west_xpm->texture;
	cube->textures->south = &cube->textures->south_xpm->texture;
	cube->textures->east = &cube->textures->east_xpm->texture;
	// todo tratar erro mlx_load_png
}
