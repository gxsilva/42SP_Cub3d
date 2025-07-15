/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:47:44 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/30 13:45:18 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	error_msg(char *err_str, char *color, int debug_opt, int std_opt)
{
	if (debug_opt)
		perror(strerror(errno));
	free_cube(get_cube());
	if (std_opt)
	{
		printf ("Error\n");
		print_color (err_str, color);
		exit (1);
	}
}

int	error_stay(char *err_str, char *color)
{
	print_color (err_str, color);
	return (0);
}
