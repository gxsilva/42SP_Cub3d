/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 20:13:03 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/25 18:15:50 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void		ft_fill_arr(char const *s, char c, char **arr);
static size_t	ft_len_substr(const char *s, char c);
static size_t	ft_count_substr(const char *s, char c);

static void	ft_fill_arr(char const *s, char c, char **arr)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = ft_len_substr(s, c);
			arr[i] = (char *)malloc((len + 1) * sizeof(char));
			if (!arr[i])
			{
				while (i > 0)
					free(arr[--i]);
				free(arr);
				return ;
			}
			ft_strlcpy(arr[i], s, len + 1);
			i++;
			s += len;
		}
		else
			s++;
	}
	arr[i] = NULL;
}

static size_t	ft_len_substr(const char *s, char c)
{
	size_t	length;

	length = 0;
	while (s[length] && s[length] != c)
		length++;
	return (length);
}

static size_t	ft_count_substr(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	num_substr;
	char	**array;

	if (!s)
		return (NULL);
	num_substr = ft_count_substr(s, c);
	array = (char **)malloc((num_substr + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	ft_fill_arr(s, c, array);
	return (array);
}
