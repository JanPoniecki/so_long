/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_blocks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:49:00 by jponieck          #+#    #+#             */
/*   Updated: 2024/03/29 22:53:03 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_blocks(t_window *w)
{
	w->h_image = mlx_xpm_file_to_image(w->mlx, "./graph/dog.xpm", \
		&(w->h_xsize), &(w->h_ysize));
	w->land = mlx_xpm_file_to_image(w->mlx, "./graph/grss.xpm", \
		&(w->h_xsize), &(w->h_ysize));
	w->wall = mlx_xpm_file_to_image(w->mlx, "./graph/wall.xpm", \
		&(w->h_xsize), &(w->h_ysize));
	w->coll = mlx_xpm_file_to_image(w->mlx, "./graph/bone.xpm", \
		&(w->h_xsize), &(w->h_ysize));
	w->exit = mlx_xpm_file_to_image(w->mlx, "./graph/shed.xpm", \
		&(w->h_xsize), &(w->h_ysize));
	w->scss = mlx_xpm_file_to_image(w->mlx, "./graph/shdd.xpm", \
		&(w->h_xsize), &(w->h_ysize));
	w->lndd = mlx_xpm_file_to_image(w->mlx, "./graph/grsd.xpm", \
		&(w->h_xsize), &(w->h_ysize));
}
