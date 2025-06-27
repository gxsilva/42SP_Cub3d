/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:47:44 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/27 15:35:58 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	error_msg(char *err_str, char *color, int debug_opt, int std_opt)
{
	if (debug_opt)
		perror(strerror(errno));
	if (std_opt)
	{
		printf ("Error\n");
		print_color (err_str, color);
		exit (1);
	}
}

int	error_stay(char *err_str)
{
	printf("%s\n", err_str);
	return (0);
}
