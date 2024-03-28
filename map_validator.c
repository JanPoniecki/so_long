/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:52:25 by jponieck          #+#    #+#             */
/*   Updated: 2024/03/28 21:57:05 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_validator(t_window *window)
{
	int	row;
	int	col;

	window->items = 0;
	window->e_status = 0;
	row = 0;
	col = 0;
	while (window->map[row])
	{
		while (window->map[row][col])
		{
			if (window->map[row][col] == 'C')
				window->items++;
			col++;
		}
		row++;
		col = 0;
	}
}
