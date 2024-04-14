/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 22:47:19 by jponieck          #+#    #+#             */
/*   Updated: 2024/04/13 20:54:33 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef RES
#  define RES 100
# endif

# include "mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <string.h>
# include <errno.h>

typedef struct s_node
{
	char	id[2];
	char	nrbs[8];
}	t_node;

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
	void	*sign;
	int		moves;
}	t_window;

char	*read_map(t_window *window, char *map_str, char* temp, char* temp1);
void	check_path(t_window *window);
int		map_validator(t_window *window);
void	init_blocks(t_window *w);
void	end_game(t_window *w, char *message);
int		count_fields(t_window *window, int i, int j);
void	aval_from_start(t_window *w, t_node **nodes, int i, int j);
int		int_color(unsigned char t, unsigned char r, \
	unsigned char g, unsigned char b);
int		move_hero(int key, t_window *window);
int		check_click();
int		is_wall(int x, int y, t_window *window);
int		time_to_go(t_window *window);
void	exit_error(t_window *w, char *message, int e_id);

#endif
