/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changeMemVal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 15:28:04 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/17 12:26:26 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		changeMemVal(t_data *d, int id, int where, char *str)
{
	size_t			i;
	unsigned char	tmp[3];

	i = 0;
	ft_bzero(tmp, 3);
	while (i < REG_SIZE)
	{
		if (str[i] == 0)
			ft_strncpy((char *)&tmp, "00", 2);
		else
			ft_putHexNbr(str[i], &tmp);
		d->map[where].hex[0] = tmp[0];
		d->map[where].hex[1] = tmp[1];
		d->map[where].recent = 20;
		d->map[where].champ = id;
		i++;
		where = (where + 1) % (MEM_SIZE);
	}
	return (0);
}
