/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:18:47 by jponieck          #+#    #+#             */
/*   Updated: 2024/04/19 15:06:58 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	open_map(char *src, t_window *w)
{
	int	fd;

	fd = open(src, O_RDONLY);
	if (!fd || fd == -1)
	{
		ft_printf("Error reading '%s': %s\n", src, strerror(errno));
		exit_error(w, "check map filename", 1, NULL);
	}
	return (fd);
}

int	check_for_empty_line(char *map_str)
{
	int	i;
	int	ns;

	i = 0;
	ns = 0;
	while (map_str[i])
	{
		if (map_str[i] == '\n')
			ns++;
		else
			ns = 0;
		if (ns > 1)
			return (-1);
		i++;
	}
	return (0);
}

char	*read_map(t_window *window, char *map_str, char *temp, char *temp1)
{
	int		fd;

	fd = open_map("map.ber", window);
	while (temp)
	{
		temp = get_next_line(fd);
		if (temp)
		{
			temp1 = map_str;
			map_str = ft_strjoin(temp1, temp);
			if (!map_str)
				exit_error(window, "allocation error, try again", 1, NULL);
			if (ft_strlen(temp1) > 0)
				free(temp1);
			window->win_x = (ft_strlen(temp) - 1) * 75;
			window->win_y += 75;
			free(temp);
		}
	}
	close(fd);
	if (check_for_empty_line(map_str) == -1)
		exit_error(window, "there is an empty line in the map", 1, map_str);
	return (map_str);
}
