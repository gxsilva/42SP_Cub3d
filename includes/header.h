/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:25:45 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/26 17:22:40 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

//Standard libraries
# include <stdio.h> //printf, exit
# include <unistd.h> //write, close, read
# include <fcntl.h> //open
# include <stdlib.h> //malloc, free
# include <sys/time.h> //gettimeofday
# include <errno.h> //perror
# include <string.h> //strerror

//extern libraries
# include "../lib/GNL/includes/get_next_line.h"
# include "../lib/libft/includes/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"

//extern includes
# include "struct.h"
# include "errors.h"
# include "colors.h"
# include "macros.h"
# include "functions.h"

#endif //HEADER_H
