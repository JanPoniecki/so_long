/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:07:37 by nshahid           #+#    #+#             */
/*   Updated: 2024/02/03 19:41:31 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*test_strings(const char *big, const char *small, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (big[i])
	{
		k = i;
		while ((big[k] == small[j] && big[k]) || small[j] == '\0')
		{
			if (small[j] == '\0')
				return ((char *)&big[i]);
			j++;
			if (k == n)
				return (NULL);
			k++;
		}
		if (i == n)
			return (NULL);
		i++;
		j = 0;
	}
	return (NULL);
}

char	*ft_strnstr(const char *big, const char *small, size_t n)
{
	if (!big && n == 0)
		return (NULL);
	return (test_strings(big, small, n));
}
