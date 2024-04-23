/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:31:09 by jponieck          #+#    #+#             */
/*   Updated: 2024/04/19 15:07:57 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(char m, t_window *window, int x, int y)
{
	void	*tile;

	if (m == '1')
		tile = window->wall;
	else if (m == '0')
		tile = window->land;
	else if (m == 'C')
		tile = window->coll;
	else if (m == 'P')
	{
		tile = window->land;
		window->h_x = x;
		window->h_y = y;
	}
	else if (m == 'E')
		tile = window->exit;
	else if (m == 'S')
		tile = window->sign;
	else
		return ;
	mlx_put_image_to_window(window->mlx, window->win, tile, x, y);
}

void	init_map(char *map, t_window *window)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	window->win = mlx_new_window(window->mlx, window->win_x, \
		window->win_y, "so long");
	if (!window->win)
		exit_error(window, "allocation error", 1, NULL);
	while (*map)
	{
		if (*map != '\n')
		{
			put_img(*map, window, x, y);
			x += 75;
		}
		else
		{
			y += 75;
			x = 0;
		}
		map++;
	}
	put_img('S', window, (window->win_x) - 75, (window->win_y) - 75);
}

int	is_wall(int x, int y, t_window *window)
{
	x = x / 75;
	y = y / 75;
	if (window->map[y][x] == 'C')
	{
		window->items--;
		window->map[y][x] = '0';
	}
	if (window->map[y][x] == 'E' && window->items == 0)
	{
		window->e_status = 1;
		return (0);
	}
	if (ft_strchr("0CP", window->map[y][x]))
	{
		window->moves++;
		ft_printf("\033[2J");
		ft_printf("so far you have made %d moves\n", window->moves);
		return (0);
	}
	else
		return (1);
}

int	main(void)
{
	t_window	window;

	window.win_x = 0;
	window.win_y = 0;
	window.moves = 0;
	window.win = NULL;
	window.mlx = mlx_init();
	if (!window.mlx)
		exit_error(&window, "allocation error", 0, NULL);
	window.map_string = read_map(&window, "", "", "");
	window.map = ft_split(window.map_string, '\n');
	if (!window.map)
		exit_error(&window, "allocation error", 1, NULL);
	init_blocks(&window);
	map_validator(&window);
	init_map(window.map_string, &window);
	mlx_put_image_to_window(window.mlx, window.win, window.h_image,
		window.h_x, window.h_y);
	mlx_key_hook(window.win, move_hero, &window);
	mlx_hook(window.win, 17, 1L << 2, check_click, &window);
	mlx_loop_hook(window.mlx, time_to_go, &window);
	mlx_loop(window.mlx);
	return (0);
}
