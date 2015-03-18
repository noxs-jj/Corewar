/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int_from_dec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 14:44:00 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/03/18 14:44:01 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

/*
** conv int to dec (register) : get_int_from_dec	ok
*/

int		get_int_from_dec(char *str, int len)
{
	char	tmp[T_LAB + 1];
	int		i;
	int		index;

	ft_bzero(tmp, T_LAB + 1);
	index = len - hex_strlen((unsigned char *)str, len);
	i = 0;
	len = len - index;
	while (len > 0)
	{
		ft_put_hex_nbr(str[index], (unsigned char (*)[])(&tmp[i]));
		index++;
		len--;
		i += 2;
	}
	return ((int)ft_hex2intdec((unsigned char*)tmp));
}
