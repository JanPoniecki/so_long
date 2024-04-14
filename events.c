/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:33:59 by jponieck          #+#    #+#             */
/*   Updated: 2024/04/13 18:48:05 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_hero(int key, t_window *window)
{
	if (window->e_status == 1 || key == 120)
	{
		end_game(window, "thank you for playing so_long! :)\n");
		return (0);
	}
	mlx_put_image_to_window(window->mlx, window->win, \
		window->lndd, window->h_x, window->h_y);
	if (key == 100 && !is_wall(window->h_x + 75, window->h_y, window))
		window->h_x += 75;
	else if (key == 97 && !is_wall(window->h_x - 75, window->h_y, window))
		window->h_x -= 75;
	else if (key == 119 && !is_wall(window->h_x, window->h_y - 75, window))
		window->h_y -= 75;
	else if (key == 115 && !is_wall(window->h_x, window->h_y + 75, window))
		window->h_y += 75;
	mlx_put_image_to_window(window->mlx, window->win, \
		window->h_image, window->h_x, window->h_y);
	if (window->e_status == 1)
	{
		mlx_put_image_to_window(window->mlx, window->win, \
			window->scss, window->h_x, window->h_y);
	}
	return (0);
}

int	check_click(void)
{
	int	fd;

	fd = open("game", O_WRONLY | O_TRUNC);
	ft_putchar_fd('0', fd);
	close(fd);
	return (0);
}

int	time_to_go(t_window *window)
{
	char	game;
	int		fd;

	fd = open("game", O_RDONLY);
	read(fd, &game, 1);
	close(fd);
	if (game == '0')
		end_game(window, "thank you for playing so_long! :)\n");
	return (0);
}
