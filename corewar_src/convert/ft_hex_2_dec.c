/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_2_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 14:33:49 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/16 14:58:37 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_op_tab.h"

static int		ft_pow(int base, int exp)
{
	int result;

	result = 1;
	while (exp)
	{
		if (exp & 1)
			result *= base;
		exp >>= 1;
		base *= base;
	}
	return (result);
}

unsigned int	ft_hex_2_dec(unsigned char *str)
{
	unsigned int	result;
	unsigned int	len;
	int				i;

	i = 0;
	result = 0;
	len = ft_strlen((char *)str) - 1;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			result += (str[i] - '0') * ft_pow(16, len);
		else if (str[i] >= 'a' && str[i] <= 'f')
			result += (str[i] - 'a' + 10) * ft_pow(16, len);
		else
			return (-1);
		i++;
		len--;
	}
	return (result);
}

unsigned int	ft_hex2intdec(unsigned char *str)
{
	unsigned int	result;
	unsigned int	len;
	int				i;

	i = 0;
	result = 0;
	len = ft_strlen((char *)str) - 1;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			result += (str[i] - '0') * ft_pow(16, len);
		else if (str[i] >= 'a' && str[i] <= 'f')
			result += (str[i] - 'a' + 10) * ft_pow(16, len);
		else
			return (-1);
		i++;
		len--;
	}
	return (result);
}
