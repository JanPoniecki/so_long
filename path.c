/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:39:29 by jponieck          #+#    #+#             */
/*   Updated: 2024/03/31 20:04:21 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_fields(t_window *window, int i, int j)
{
	int	fields;

	fields = 0;
	while (window->map[i])
	{
		while (window->map[i][j])
		{
			if (window->map[i][j] != '1')
				fields++;
			j++;
		}
		i++;
		j = 0;
	}
	return (fields);
}

static t_node	**init_nodes(t_window *w, int i, int j)
{
	t_node	**nodes;
	int		n;

	n = 0;
	nodes = malloc(sizeof(void *) * (count_fields(w, i, j) + 1));
	while (w->map[i])
	{
		while (w->map[i][j])
		{
			if (w->map[i][j] != '1')
			{
				nodes[n] = malloc(sizeof(t_node));
				nodes[n]->id[0] = i;
				nodes[n]->id[1] = j;
				ft_bzero(nodes[n]->nrbs, 9);
				n++;
			}
			j++;
		}
		i++;
		j = 0;
	}
	nodes[n] = NULL;
	return (nodes);
}

static void	fill_up_neighbours_row(t_window *w, t_node **ns, int i, int j)
{
	while (ns[i])
	{
		if (w->map[ns[i]->id[0] - 1][ns[i]->id[1]] != '1')
		{
			ns[i]->nrbs[j] = ns[i]->id[0] - 1;
			ns[i]->nrbs[j + 1] = ns[i]->id[1];
			j += 2;
		}
		if (w->map[ns[i]->id[0] + 1][ns[i]->id[1]] != '1')
		{
			ns[i]->nrbs[j] = ns[i]->id[0] + 1;
			ns[i]->nrbs[j + 1] = ns[i]->id[1];
			j += 2;
		}
		i++;
		j = 0;
	}
}

static void	fill_up_neighbours_col(t_window *w, t_node **ns, int i, int j)
{
	while (ns[i])
	{
		while (ns[i]->nrbs[j] != 0)
			j++;
		if (w->map[ns[i]->id[0]][ns[i]->id[1] - 1] != '1')
		{
			ns[i]->nrbs[j] = ns[i]->id[0];
			ns[i]->nrbs[j + 1] = ns[i]->id[1] - 1;
			j += 2;
		}
		if (w->map[ns[i]->id[0]][ns[i]->id[1] + 1] != '1')
		{
			ns[i]->nrbs[j] = ns[i]->id[0];
			ns[i]->nrbs[j + 1] = ns[i]->id[1] + 1;
			j += 2;
		}
		i++;
		j = 0;
	}
}

void	check_path(t_window *window)
{
	t_node	**nodes;
	int		i;
	int		j;

	i = 0;
	j = 0;
	nodes = init_nodes(window, i, j);
	fill_up_neighbours_row(window, nodes, i, j);
	fill_up_neighbours_col(window, nodes, i, j);
	aval_from_start(window, nodes, i, j);
}
