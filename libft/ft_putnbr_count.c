/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:12:53 by jponieck          #+#    #+#             */
/*   Updated: 2024/03/02 14:12:58 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_count(int v, int fd)
{
	int	chars;

	ft_putnbr_fd(v, fd);
	chars = 0;
	if (v <= 0)
		chars ++;
	while (v != 0)
	{
		v = v / 10;
		chars ++;
	}
	return (chars);
}
