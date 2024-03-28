/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:16:53 by jponieck          #+#    #+#             */
/*   Updated: 2024/03/02 14:16:55 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_count(char *v, int fd)
{
	if (!v)
	{
		ft_putstr_fd("(null)", fd);
		return (6);
	}
	ft_putstr_fd(v, fd);
	return (ft_strlen(v));
}
