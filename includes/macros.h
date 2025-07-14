/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:35:15 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/14 16:23:43 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# ifndef DEBUG_FLAG
#  define DEBUG_FLAG 0
# endif

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 720
# endif

# ifndef TILE
#  define TILE 16
# endif

# ifndef FOV
#  define FOV 0.66
# endif

# ifndef MOUSE_SENS
#  define MOUSE_SENS 0.001
# endif

# ifndef PLAYER_SPEED
#  define PLAYER_SPEED 2.5
# endif

# ifndef ROT_SPEED
#  define ROT_SPEED 0.025
# endif

# ifndef SPRITE_CNT
#  define SPRITE_CNT 5
# endif

# ifndef SPRITE_REFRESH
#  define SPRITE_REFRESH 50
# endif

//Sprites path
# define SPRITE_01 "./sprites/frame01.png"
# define SPRITE_02 "./sprites/frame02.png"
# define SPRITE_03 "./sprites/frame03.png"
# define SPRITE_04 "./sprites/frame04.png"
# define SPRITE_05 "./sprites/frame05.png"

#endif // MACROS_H