/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 22:47:19 by jponieck          #+#    #+#             */
/*   Updated: 2024/03/29 22:53:42 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "libft/libft.h"
# include <fcntl.h>

typedef struct s_window
{
	void	*mlx;
	void	*win;
	int		win_x;
	int		win_y;
	void	*h_image;
	int		h_x;
	int		h_y;
	int		h_xsize;
	int		h_ysize;
	char	**map;
	int		items;
	int		e_status;
	void	*land;
	void	*lndd;
	void	*wall;
	void	*coll;
	void	*exit;
	void	*scss;
}	t_window;

char	*read_map(t_window *window);
int		map_validator(t_window *window);
void	init_blocks(t_window *w);
void	end_game(t_window *w, char *message);
int		int_color(unsigned char t, unsigned char r, \
	unsigned char g, unsigned char b);

#endif
