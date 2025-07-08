/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 01:34:38 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/08 02:07:28 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

char	*info_xpm_line (char *xpm_path);
char	*format_xpm_line(char *line);
void	init_texture (t_texture *texture, char *xpm_path);

char	*format_xpm_line(char *line)
{
	char *result;
	int i = 0;
	int j = 0;

	if (!line)
		return NULL;
	result = (char *)malloc(ft_strlen(line) + 1);
	if (!result)
		return NULL;
	while (line[i])
	{
		if ((line[i] >= '0' && line[i] <= '9') || line[i] == ' ')
		{
			result[j++] = line[i];
		}
		i++;
	}
	result[j] = '\0';
	return (free(line), result);
}

void	init_texture (t_texture *texture, char *xpm_path)
{
	get_dimensions(texture, xpm_path);
	init_img_xpm(texture, xpm_path);
}

char	*info_xpm_line (char *xpm_path)
{
	char	*line;
	int		fd;

	fd = open(xpm_path, O_RDONLY);
	free (get_next_line(fd));
	line = get_next_line(fd);
	close (fd);
	return (line);
}