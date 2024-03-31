/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:52:25 by jponieck          #+#    #+#             */
/*   Updated: 2024/03/30 20:42:27 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_shape(t_window *window, int row)
{
	size_t	col_size;

	while (window->map[row])
	{
		if (row == 0)
			col_size = ft_strlen(window->map[row]);
		else
		{
			if (ft_strlen(window->map[row]) != col_size)
				return (-1);
		}
		row++;
	}
	return (0);
}

static int	check_borders(t_window *window, int row, int col)
{
	while (window->map[row])
	{
		if (row == 0 || window->map[row + 1] == NULL)
		{
			while (window->map[row][col])
			{
				if (window->map[row][col] != '1')
					return (-1);
				col++;
			}
		}
		if (window->map[row][0] != '1' || \
			window->map[row][ft_strlen(window->map[row]) - 1] != '1')
			return (-1); 
		row++;
		col = 0;
	}
	return (0);
}

static void	check_chars(t_window *w, int row, int col, char *vaild_chars)
{
	int		ps;
	int		es;

	ps = 0;
	es = 0;
	while (w->map[row])
	{
		while (w->map[row][col])
		{
			if (w->map[row][col] == 'C')
				w->items++;
			if (w->map[row][col] == 'P')
				ps++;
			if (w->map[row][col] == 'E')
				es++;
			if (!ft_strchr(vaild_chars, w->map[row][col]))
				end_game(w, "unknown characters in map file \n");
			col++;
		}
		row++;
		col = 0;
	}
	if (ps != 1 || es != 1)
		end_game(w, "incorrect number of heroes or exits in map file \n");
}

int	map_validator(t_window *window)
{
	int	row;
	int	col;

	window->items = 0;
	window->e_status = 0;
	row = 0;
	col = 0;
	if (check_shape(window, row) != 0)
		end_game(window, "shape is not rectangular :/ \n");
	if (check_borders(window, row, col) != 0)
		end_game(window, "not all borders are walls \n");
	check_chars(window, row, col, "10EPC");
	check_path(window);
	return (0);
}
