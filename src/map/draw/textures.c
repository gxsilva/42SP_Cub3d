/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:09:58 by ailbezer          #+#    #+#             */
/*   Updated: 2025/07/08 20:01:28 by ailbezer         ###   ########.fr       */
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
	// if (access("./old_textures/simonkraft/respawn_anchor_side0.xpm42", F_OK) == -1)
	// 	perror("Arquivo não encontrado:");
	// else
	// 	puts("Arquivo encontrado!");

	// cube->textures->north = mlx_load_png("./old_textures/simonkraft/fundo-de-textura-de-parede-branca-de-concreto-em-branco.png");
	// cube->textures->south = mlx_load_png("./old_textures/simonkraft/fundo-de-textura-de-parede-branca-de-concreto-em-branco.png");
	// cube->textures->east = mlx_load_png("./old_textures/simonkraft/fundo-de-textura-de-parede-branca-de-concreto-em-branco.png");
	// cube->textures->west = mlx_load_png("./old_textures/simonkraft/fundo-de-textura-de-parede-branca-de-concreto-em-branco.png");

	// cube->textures->north = mlx_load_png("./old_textures/simonkraft/eagle.png");
	// cube->textures->south = mlx_load_png("./old_textures/simonkraft/eagle.png");
	// cube->textures->east = mlx_load_png("./old_textures/simonkraft/eagle.png");
	// cube->textures->west = mlx_load_png("./old_textures/simonkraft/eagle.png");

	cube->textures->north = mlx_load_png("./old_textures/simonkraft/image.png");
	cube->textures->south = mlx_load_png("./old_textures/simonkraft/image.png");
	cube->textures->east = mlx_load_png("./old_textures/simonkraft/image.png");
	cube->textures->west = mlx_load_png("./old_textures/simonkraft/image.png");
	
	// cube->textures->north = &cube->textures->north_xpm->texture;
	// cube->textures->west = &cube->textures->west_xpm->texture;
	// cube->textures->south = &cube->textures->south_xpm->texture;
	// cube->textures->east = &cube->textures->east_xpm->texture;
	// todo tratar erro mlx_load_png/nfs/homes/ailbezer/Downloads/eagle.png
}
