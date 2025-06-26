/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_file_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:54:31 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/25 19:05:16 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int		count_elements(char **array);
int		rgb_to_int(char *str);

/*
int	count_elements(char **array)
{
	int count = 0;

	if (!array)
		return (0);
	while (array[count] != NULL)
	{
		if (strlen_space(sanitize_string(array[count])) != 0)
			count++;
		else
			break;
	}
	return (count);
}
*/

int	count_elements(char **array)
{
	int		count;
	int		j;
	char	*sanitized;
	int		len;

	count = 0;
	if (!array)
		return (0);
	while (array[count] != NULL)
	{
		sanitized = sanitize_string(array[count]);
		len = strlen_space(sanitized);
		if (len == 0)
			break;
		j = 0;
		while (j < len)
		{
			if (!ft_isdigit(sanitized[j]))
				return (0);
			j++;
		}
		count++;
	}
	return (count);
}

int	rgb_to_int(char *str)
{
	int		color;
	char	**rgb;
	
	str[ft_strlen(str) - 1] = '\0';
	rgb = ft_split(str, ',');
	if (count_elements(rgb) != 3)
	{
		free_split((void **)rgb);
		return (-1);
	}
	color = (ft_atoi(rgb[0]) << 16) | (ft_atoi(rgb[1]) << 8) | ft_atoi(rgb[2]);
	free_split((void **)rgb);
	return (color);
}

