/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:48:15 by jponieck          #+#    #+#             */
/*   Updated: 2024/03/01 15:48:24 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *src, ...)
{
	int		chars;
	va_list	ap;

	va_start(ap, src);
	chars = print_stuff(src, ap);
	va_end(ap);
	return (chars);
}
