/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr_2_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 16:12:28 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/03/18 16:12:29 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_op_tab.h"

void ft_put_nbr_2_hex(int len, unsigned char (*src)[], unsigned char (*str)[])
{
	int i;
	int index;

	i = 0;
	index = 0;
	while (i < len && (*src)[i] == 0)
	{
		len++;
		i++;
	}
	write_l(ft_itoa(len));
	while (i < len)
	{
		ft_put_hex_nbr((*src)[i], (unsigned char (*)[])&(*str)[index * 2]);
		index++;
		i++;
	}
}
