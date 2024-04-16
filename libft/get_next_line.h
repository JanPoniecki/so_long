/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 22:33:25 by jponieck          #+#    #+#             */
/*   Updated: 2024/03/16 19:48:22 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 40
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		count_tools(char *src, char c, int mode, int size);
char	*string_tools(char *src, int mode, int start);
int		cut_copy_string(char *src, int start, char *dest, int size);
char	*check_last(char *line, int *mode_4, int res);
char	*get_from_buffer(char *buffer, int *mode);

#endif
