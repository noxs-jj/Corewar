/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr2dec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 14:43:50 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/03/18 14:43:50 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

void	hex2dec(unsigned char (*src)[], unsigned char (*str)[], int size)
{
	size_t	len;
	int		i;
	char	tmp[3];
	int		result;

	len = ft_strlen((char *)*src) / 2;
	i = 0;
	size = size - len;
	while (i < (int)len)
	{
		ft_bzero(tmp, 3);
		ft_strncpy(tmp, (char *)&(*src)[i * 2], 2);
		result = ft_hex2intdec((unsigned char *)tmp);
		(*str)[size + i] = result;
		i++;
	}
}
