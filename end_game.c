/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:07:33 by jponieck          #+#    #+#             */
/*   Updated: 2024/03/28 22:48:55 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_game(t_window *w)
{
	mlx_destroy_image(w->mlx, w->h_image);
	mlx_destroy_image(w->mlx, w->land);
	mlx_destroy_image(w->mlx, w->wall);
	mlx_destroy_image(w->mlx, w->coll);
	mlx_destroy_image(w->mlx, w->exit);
	mlx_destroy_image(w->mlx, w->scss);
	mlx_destroy_window(w->mlx, w->win);
	free_split(w->map);
	free(w->mlx);
	ft_printf("Thank you for playing 'so long' :)\n");
	exit(0);
}