/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:07:37 by nshahid           #+#    #+#             */
/*   Updated: 2023/05/27 12:07:37 by nshahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	m;
	int	i;

	i = 0;
	if (!src && !dest)
		return (NULL);
	if (src + n > dest && dest > src && n > 0)
	{
		i += (n -1);
		m = -1;
	}
	else
		m = 1;
	while (n > 0)
	{
		((char *)dest)[i] = ((char *)src)[i];
		if (n != 1)
			i += 1 * m;
		n--;
	}
	return (dest);
}
