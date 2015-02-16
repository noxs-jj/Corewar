/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readOpCode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 15:20:27 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/16 16:09:34 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewarOpTab.h"

/*
** Read OP Code, convert it into binary (8 chars)
*/

int	readOpCode(t_data *d, int player)
{
	int	i;
	t_case *args;

	args = ((d->prog[player].PC) + 1);
	ft_bzero(d->prog[player].opArgs, 9);
	while (i < 16)
	{
		if ( !(args->hex[0] >= 'a' && args->hex[0] <= 'f')
			&& !(args->hex[0] >= '0' && args->hex[0] <= '9'))
			return (-1);
		if (bin_tab[i].hex == args->hex[0])
			ft_strncpy(d->prog[player].opArgs, bin_tab[i].bin, 4);
		i++;
	}
	i = 0;
	while (i < 16)
	{
		if ( !(args->hex[1] >= 'a' && args->hex[1] <= 'f')
			&& !(args->hex[1] >= '0' && args->hex[1] <= '9'))
			return (-1);
		if (bin_tab[i].hex == args->hex[1])
			ft_strncpy(&d->prog[player].opArgs[4], bin_tab[i].bin, 4);
		i++;
	}
	return (0);
}