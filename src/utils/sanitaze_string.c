/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitaze_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:52:15 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/25 18:52:23 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

char *sanitize_string(char *line)
{
	int		i;

	i = 0;
	if (!line)
		error_msg(NULL_POINTER, DEBUG_FLAG, 1);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	int j = 0;
	while (line[j])
	{
		if (!ft_isascii(line[j]))
			error_msg(INVALID_FILE_CHAR, DEBUG_FLAG, 1);
		j++;
	}
	return (&line[i]);
}