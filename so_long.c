/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:31:09 by jponieck          #+#    #+#             */
/*   Updated: 2024/03/28 22:46:03 by jponieck         ###   ########.fr       */
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
	else
		return;
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
	while (*map)
	{
		if (*map != '\n')
		{
			put_img(*map, window, x, y);
			x += 100;
		}
		else
		{
			y += 100;
			x = 0;
		}
		map++;
	}
}

int	is_wall(int x, int y, t_window *window)
{
	x = x / 100;
	y = y / 100;
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
		return (0);
	else
		return (1);
}

int	move_hero(int key, t_window *window)
{
	if (window->e_status == 1 || key == 120)
	{
		end_game(window);
		return (0);
	}
	mlx_put_image_to_window(window->mlx, window->win, \
		window->land, window->h_x, window->h_y);
	if (key == 100 && !is_wall(window->h_x + 100, window->h_y, window))
		window->h_x += 100;
	else if (key == 97 && !is_wall(window->h_x - 100, window->h_y, window))
		window->h_x -= 100;
	else if (key == 119 && !is_wall(window->h_x, window->h_y - 100, window))
		window->h_y -= 100;
	else if (key == 115 && !is_wall(window->h_x, window->h_y + 100, window))
		window->h_y += 100;
	mlx_put_image_to_window(window->mlx, window->win, \
		window->h_image, window->h_x, window->h_y);
	if (window->e_status == 1)
	{
		mlx_put_image_to_window(window->mlx, window->win, \
			window->scss, window->h_x, window->h_y);
	}
	return (0);
}

int	main(void)
{
	char		*map;
	t_window	window;

	window.win_x = 0;
	window.win_y = 0;
	window.mlx = mlx_init();
	map = read_map(&window);
	window.map = ft_split(map, '\n');
	init_blocks(&window);
	map_validator(&window);
	init_map(map, &window);
	mlx_put_image_to_window(window.mlx, window.win, window.h_image, \
		window.h_x, window.h_y);
	mlx_key_hook(window.win, move_hero, &window);
	mlx_loop(window.mlx);
	free(map);
	return (0);
}
