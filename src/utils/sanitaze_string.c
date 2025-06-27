/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitaze_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:52:15 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/27 15:37:19 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

char	*sanitize_string(char *line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!line)
		error_msg(NULL_POINTER, BRIGHT_RED, DEBUG_FLAG, 1);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	while (line[j])
	{
		if (!ft_isascii(line[j]))
			error_msg(INVALID_FILE_CHAR, BRIGHT_RED, DEBUG_FLAG, 1);
		j++;
	}
	return (&line[i]);
}
