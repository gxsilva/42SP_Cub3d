/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:47:44 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/24 16:05:12 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	error_msg (char *err_str, int debug_opt, int std_opt)
{
	if (debug_opt)
	{
		perror(strerror(errno));
		printf ("%s\n", err_str);
	}
	if (std_opt)
	{
		printf("Error\n");
		exit (1);
	}
}
