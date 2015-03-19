/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_hex_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 14:43:19 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/03/18 14:43:20 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_op_tab.h"

int		str_hex_len(unsigned char *str)
{
	unsigned int	value;
	int				len;

	len = 1;
	value = ft_hex2intdec(str);
	while (value > 255)
	{
		value /= 255;
		len++;
	}
	return (len);
}
