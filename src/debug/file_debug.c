/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_debug.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:30:51 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/06/26 17:30:36 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	debug_file_struct(t_file *file)
{
	printf("\e[36mFile struct information:\e[0m\n");
	printf("\e[33mCeiling Color:\e[0m \e[32m%d\e[0m\n", file->ceiling);
	printf("\e[33mFloor Color:\e[0m \e[32m%d\e[0m\n", file->floor);
	printf("\e[33mEA_path:\e[0m \e[34m%s\e[0m\n", file->ea_path);
	printf("\e[33mNO_path:\e[0m \e[34m%s\e[0m\n", file->no_path);
	printf("\e[33mSO_path:\e[0m \e[34m%s\e[0m\n", file->so_path);
	printf("\e[33mWE_path:\e[0m \e[34m%s\e[0m\n", file->we_path);
}
