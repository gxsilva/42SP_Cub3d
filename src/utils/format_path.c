/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:48:01 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/30 10:28:51 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	format_path(char **xpm_path)
{
	char	*new_str;
	int		i;

	i = -1;
	new_str = (char *)malloc(ft_strlen(*xpm_path) + 3);
	if (!new_str)
		error_msg(INVALID_MALLOC, BRIGHT_RED, DEBUG_FLAG, 1); //TODO correct handle free structs
	new_str[0] = '.';
	new_str[1] = '/';
	while ((*xpm_path)[++i])
		new_str[i + 2] = (*xpm_path)[i];
	new_str[i + 2] = '\0';
	free (*xpm_path);
	*xpm_path = new_str;
}
