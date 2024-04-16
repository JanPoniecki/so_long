/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:07:33 by jponieck          #+#    #+#             */
/*   Updated: 2024/04/16 13:56:59 by jponieck         ###   ########.fr       */
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
	mlx_destroy_image(w->mlx, w->sign);
	if (w->e_status == 1)
		ft_printf("you finished the game with %d moves!\n", w->moves);
	if (w->win)
		mlx_destroy_window(w->mlx, w->win);
	free_split(w->map);
	mlx_destroy_display(w->mlx);
	free(w->mlx);
	ft_printf("%s \n", message);
	exit(0);
}

void	exit_error(t_window *w, char *message, int e_id)
{
	ft_printf("%s\n", message);
	if (e_id == 1)
	{
		mlx_destroy_display(w->mlx);
		free(w->mlx);
	}
	exit(0);
}
