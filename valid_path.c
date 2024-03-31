/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 16:29:16 by jponieck          #+#    #+#             */
/*   Updated: 2024/03/31 20:34:16 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_in_avals(int x, int y, char *avals)
{
	char	node[4];

	node[0] = x;
	node[1] = '.';
	node[2] = y;
	node[3] = 0;
	if (ft_strnstr(avals, node, ft_strlen(avals)))
		return (1);
	else
		return (0);
}

static void	add_to_avals(int x, int y, char *avals)
{
	int	i;

	i = 0;
	while (avals[i])
		i++;
	avals[i] = x;
	avals[i + 1] = '.';
	avals[i + 2] = y;
}

static void	find_start(t_window *w, int i, int j)
{
	while (w->map[i])
	{
		while (w->map[i][j])
		{
			if (w->map[i][j] == 'P')
			{
				w->h_x = i;
				w->h_y = j;
			}
			j++;
		}
		i++;
		j = 0;
	}
}

static void	find_connections(char	*avals, t_node **ns, int x, int y)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	if (is_in_avals(x, y, avals) == 0)
	{
		add_to_avals(x, y, avals);
		while (1)
		{
			if (ns[i]->id[0] == x && ns[i]->id[1] == y)
				break ;
			i++;
		}
		while (ns[i]->nrbs[j] != 0)
		{
			find_connections(avals, ns, ns[i]->nrbs[j], ns[i]->nrbs[j + 1]);
			j += 2;
		}
	}
}

void	aval_from_start(t_window *w, t_node **nodes, int i, int j)
{
	char	*avals;
	int		elements;

	elements = count_fields(w, 0, 0);
	avals = ft_calloc(elements * 3 + 1, 1);
	find_start(w, 0, 0);
	find_connections(avals, nodes, w->h_x, w->h_y);
	while (w->map[i])
	{
		while (w->map[i][j])
		{
			if (w->map[i][j] == 'C' || w->map[i][j] == 'E')
			{
				if (is_in_avals(i, j, avals) == 0)
					end_game(w, "there is no valid path for some \
						collectables or for the exit\n");
			}
			j++;
		}
		i++;
		j = 0;
	}
	free (avals);
}
