/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 15:27:32 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/03/18 15:27:33 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

int		arg_to_dec(char (*src)[])
{
	char	str[T_LAB2];
	char	tmp[3];
	int		i;

	ft_bzero(str, T_LAB2);
	i = 0;
	while (str[i] == 0)
		i++;
	while (i < T_LAB)
	{
		ft_bzero(tmp, 3);
		ft_put_hex_nbr((unsigned char)(*src)[i], (unsigned char (*)[])&tmp);
		ft_strncpy(&str[i * 2], tmp, 2);
		i++;
	}
	return (ft_hex2intdec((unsigned char *)str));
}
