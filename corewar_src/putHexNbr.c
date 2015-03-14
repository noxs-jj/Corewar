/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putHexNbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 16:26:01 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/14 15:50:52 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_putHexNbr(unsigned char n, char (*str)[])
{
	static char tab[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
							'a', 'b', 'c', 'd', 'e', 'f'};

	writeL("HEX");
	if (n < 16)
	{
		(*str)[0] = '0';
		(*str)[1] = tab[n];
	}
	else
	{
		(*str)[0] = tab[(n / 16) % 16];
		(*str)[1] = tab[n % 16];
	}
}
/*
**
** 10		0a		ok
** 255		ff		ok
** 1 0		01 00	ok
**
*/

// if str == 0 0 255, len == 3
void ft_putNbr2hex(int len, char (*src)[], char (*str)[])
{
	int i;
	int index;

	i = 0;
	index = 0;
	writeL("in test");
	while (i < len && (*src)[i] == 0)
	{
		len++;
		i++;
	}
	writeL(ft_itoa(len));
	while (i < len)
	{
		writeL("before ft_putHexNbr call");
		ft_putHexNbr((*src)[i], &(*str)[index * 2]);
		index++;
		i++;
	}
}

// conv int to hex
void	ft_putHexBNbr(unsigned int n, char (*str)[])// old, delete
{
	static char tab[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
							'a', 'b', 'c', 'd', 'e', 'f'};
	char		tmp[9];
	int i;
	int j;

	i = 8;
	ft_bzero(tmp, 9);
	while (n > 0 && i >= 0)
	{
		tmp[i] = tab[n % 16];
		n /= 16;
		i--;
	}
	i++;
	j = 0;
	while (i < 9)
	{
		(*str)[j] = tmp[i];
		writeL("//////");
		writeL(ft_itoa(n));
		i++;
		j++;
	}
}
