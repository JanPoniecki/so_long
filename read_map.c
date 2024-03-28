/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:18:47 by jponieck          #+#    #+#             */
/*   Updated: 2024/03/28 21:57:52 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_map(t_window *window)
{
	int		fd;
	char	*map_str;
	char	*temp;
	char	*temp1;

	map_str = "";
	temp = "";
	temp1 = "";
	fd = open("map.ber", O_RDONLY);
	while (temp)
	{
		temp = get_next_line(fd);
		if (temp)
		{
			temp1 = map_str;
			map_str = ft_strjoin(temp1, temp);
			if (ft_strlen(temp1) > 0)
				free(temp1);
			window->win_x = (ft_strlen(temp) - 1) * 100;
			window->win_y += 100;
		}
		free(temp);
	}
	close(fd);
	return (map_str);
}
