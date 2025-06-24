/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:47:44 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/24 16:39:45 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	error_msg(char *err_str, int debug_opt, int std_opt)
{
	if (debug_opt)
		perror(strerror(errno));
	if (std_opt)
	{
		printf("Error\n");
		printf ("%s\n", err_str);
		exit (1);
	}
}
