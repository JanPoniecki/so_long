/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:07:33 by jponieck          #+#    #+#             */
/*   Updated: 2024/03/29 22:53:32 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_game(t_window *w, char *message)
{
	mlx_destroy_image(w->mlx, w->h_image);
	mlx_destroy_image(w->mlx, w->land);
	mlx_destroy_image(w->mlx, w->lndd);
	mlx_destroy_image(w->mlx, w->wall);
	mlx_destroy_image(w->mlx, w->coll);
	mlx_destroy_image(w->mlx, w->exit);
	mlx_destroy_image(w->mlx, w->scss);
	if (w->win)
		mlx_destroy_window(w->mlx, w->win);
	free_split(w->map);
	free(w->mlx);
	ft_printf("%s \n", message);
	exit(0);
}
