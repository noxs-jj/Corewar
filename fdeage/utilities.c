/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 22:50:03 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/20 15:18:52 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*get_code(unsigned char n, char tab[2])
{
	char	g;
	char	d;

	g = n / 16;
	d = n - (g * 16);
	if (g >= 10)
		tab[0] = g + 87;
	else
		tab[0] = g + '0';
	if (d >= 10)
		tab[1] = d + 87;
	else
		tab[1] = d + '0';
	fprintf(stderr, "PRINTHEX: %c%c\n", tab[0], tab[1]);
	return (tab);
}
