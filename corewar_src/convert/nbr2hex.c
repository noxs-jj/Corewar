/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr2hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 14:43:37 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/03/18 14:43:37 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

void	nbr2hex(unsigned int n, unsigned char (*str)[])
{
	static char tab[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
							'a', 'b', 'c', 'd', 'e', 'f'};
	char		tmp[9];
	int 		i;
	int 		j;

	i = 8;
	ft_bzero(tmp, 9);
	while (n > 0 && i >= 0)
	{
		tmp[i] = tab[n % 16];
		n /= 16;
		i--;
	}
	if (i % 2 != 0)
		tmp[i] = '0';
	else
		i++;
	j = 0;
	while (i < 9)
	{
		(*str)[j] = tmp[i];
		i++;
		j++;
	}
}
