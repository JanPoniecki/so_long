/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:43:55 by jponieck          #+#    #+#             */
/*   Updated: 2024/03/28 18:38:23 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// funkcja odczytująca kolor jako integer (z bajtów)
int	int_color(unsigned char t, unsigned char r, \
	unsigned char g, unsigned char b)
{
	char	color[4];

	color[0] = b;
	color[1] = g;
	color[2] = r;
	color[3] = t;
	return (*(int *)color);
}
