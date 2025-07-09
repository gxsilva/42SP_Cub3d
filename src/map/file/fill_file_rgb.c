/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_file_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:54:31 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/09 17:36:09 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

int			count_elements(char **array);
uint32_t	rgba_to_int(char *str);

int	count_elements(char **array)
{
	int		idx;
	char	*sanitized;
	int		len;
	int		i;

	idx = 0;
	if (!array)
		return (0);
	while (array[idx] != NULL)
	{
		sanitized = sanitize_string(array[idx]);
		len = strlen_space(sanitized);
		if (len == 0)
			break ;
		i = 0;
		while (i < len)
		{
			if (!ft_isdigit(sanitized[i]))
				return (0);
			i++;
		}
		idx++;
	}
	return (idx);
}

uint32_t	rgba_to_int(char *str)
{
	uint32_t	color;
	char		**rgb;

	str[ft_strlen(str) - 1] = '\0';
	rgb = ft_split(str, ',');
	if (count_elements(rgb) != 3)
	{
		free_split((void **)rgb);
		return (-1);
	}
	color = (ft_atoi(rgb[0]) << 24) | (ft_atoi(rgb[1]) << 16) | (ft_atoi(rgb[2]) << 8) | 0xFF;
	free_split((void **)rgb);
	return (color);
}
