/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 17:11:27 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/27 17:50:43 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
** convert string to int
*/

int	get_arg_int(char *str)
{
	int		value;
	char	tmp[DIR + 1];

	ft_memset(tmp, 'f', DIR);
	tmp[DIR] = '\0';

	value = 0;
	if (str[0] == 'f')
		value = (int)(ft_hex2Dec((unsigned char *)str) - ft_hex2Dec((unsigned char *)tmp) - 1);//CAST
	else
		value = ft_hex2Dec((unsigned char *)str);//CAST
	return (value);
}
