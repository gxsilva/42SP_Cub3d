/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:35:15 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/07/14 19:36:01 by lsilva-x         ###   ########.fr       */
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
#  define SPRITE_CNT 12
# endif

# ifndef SPRITE_REFRESH
#  define SPRITE_REFRESH 3
# endif

//Sprites path
# define SPRITE_01 "./sprites/abra_frame01.png"
# define SPRITE_02 "./sprites/abra_frame02.png"
# define SPRITE_03 "./sprites/abra_frame03.png"
# define SPRITE_04 "./sprites/abra_frame04.png"
# define SPRITE_05 "./sprites/abra_frame05.png"
# define SPRITE_06 "./sprites/abra_frame06.png"
# define SPRITE_07 "./sprites/abra_frame07.png"
# define SPRITE_08 "./sprites/abra_frame08.png"
# define SPRITE_09 "./sprites/abra_frame09.png"
# define SPRITE_10 "./sprites/abra_frame10.png"
# define SPRITE_11 "./sprites/abra_frame11.png"
# define SPRITE_12 "./sprites/abra_frame12.png"

#endif // MACROS_H