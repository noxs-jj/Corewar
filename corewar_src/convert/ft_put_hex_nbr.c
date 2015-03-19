/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 16:11:57 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/03/18 16:11:58 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_op_tab.h"

void	ft_put_hex_nbr(unsigned char n, unsigned char (*str)[])
{
	if (n < 16)
	{
		(*str)[0] = '0';
		(*str)[1] = g_tab[n];
	}
	else
	{
		(*str)[0] = g_tab[(n / 16) % 16];
		(*str)[1] = g_tab[n % 16];
	}
}
