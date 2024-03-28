/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:07:37 by nshahid           #+#    #+#             */
/*   Updated: 2024/02/04 22:43:34 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	move_index(char const *s1, char const *set)
{
	int		i;

	i = 0;
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	return (i);
}

int	move_index_back(char const *s1, char const *set)
{
	int		i;
	int		j;

	i = ft_strlen(s1);
	j = 0;
	while (ft_strchr(set, s1[i]) && i > 0)
	{
		i--;
		j++;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*trmd;
	const char	*s0;
	int			i;

	if (!s1 || !set)
		return (NULL);
	s1 += move_index(s1, set);
	i = ft_strlen(s1) - move_index_back(s1, set);
	s0 = s1 + i;
	trmd = (char *)malloc(sizeof(char) * (i + 2));
	if (!trmd)
		return (NULL);
	i = 0;
	while (s1 != s0)
		trmd[i++] = *s1++;
	trmd[i++] = *s0;
	trmd[i] = 0;
	return (trmd);
}
