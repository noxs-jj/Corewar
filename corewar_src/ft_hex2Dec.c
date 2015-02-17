/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex2Dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 14:33:49 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/17 16:20:52 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewarOpTab.h"

static int ft_pow(int base, int exp)
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

unsigned int	ft_hex2Dec(char *str)
{
	unsigned int	result;
	unsigned int	len;
	int				i;

	i = 0;
	result = 0;
	len = ft_strlen(str) - 1;
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
	// if (result == 2014)
	// 	writeL("Test success");
	// else
	// 	writeL("Test failed");
	return (result);
}


// unsigned int	ft_hex2Dec(char *str)
// {
// 	unsigned int	result;
// 	unsigned int	i;
// 	unsigned int	y;
// 	unsigned int	tmp;
// 	unsigned int	len;

// 	i = 0;
// 	len = ft_strlen(str);
// 	while(str[i] != '\0')
// 	{
// 		y = 0;
// 		while (y < 16)
// 		{
// 			if (str[i] == deci_tab[y].hex)
// 				tmp = deci_tab[y].deci;
// 			y++;
// 		}
// 		result += tmp * ft_pow(16, len - 1);
// 		i++;
// 		len--;
// 	}
// 	// if (result == 3149642683)
// 	// 	writeL("Test success");
// 	// else
// 	// 	writeL("Test failed");
// 	return (result);
// }