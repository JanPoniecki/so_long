/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_blocks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:49:00 by jponieck          #+#    #+#             */
/*   Updated: 2024/04/19 15:08:29 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_images(t_window *w)
{
	if (w->h_image)
		mlx_destroy_image(w->mlx, w->h_image);
	if (w->land)
		mlx_destroy_image(w->mlx, w->h_image);
	if (w->wall)
		mlx_destroy_image(w->mlx, w->h_image);
	if (w->coll)
		mlx_destroy_image(w->mlx, w->h_image);
	if (w->exit)
		mlx_destroy_image(w->mlx, w->h_image);
	if (w->scss)
		mlx_destroy_image(w->mlx, w->h_image);
	if (w->lndd)
		mlx_destroy_image(w->mlx, w->h_image);
	if (w->sign)
		mlx_destroy_image(w->mlx, w->h_image);
}

static void	check_alloc(t_window *w, int errors)
{
	if (!w->h_image)
		errors++;
	if (!w->land)
		errors++;
	if (!w->wall)
		errors++;
	if (!w->coll)
		errors++;
	if (!w->exit)
		errors++;
	if (!w->scss)
		errors++;
	if (!w->lndd)
		errors++;
	if (!w->sign)
		errors++;
	if (errors > 0)
	{
		destroy_images(w);
		exit_error(w, "allocation error", 1, NULL);
	}
}

void	init_blocks(t_window *w)
{
	int	fd;

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
	w->sign = mlx_xpm_file_to_image(w->mlx, "./graph/sign.xpm", \
		&(w->h_xsize), &(w->h_ysize));
	check_alloc(w, 0);
	fd = open("game", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	ft_putchar_fd('1', fd);
	close(fd);
}
