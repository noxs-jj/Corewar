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

/*
** Ok
*/


int		changeMemVal(t_data *d, int id, int where, char *str)
{
	size_t			i;
	unsigned char	tmp[3];

	i = 0;
	ft_bzero(tmp, 3);
	while (i < REG_SIZE)
	{
		if (str[i] == 0)
			ft_strncpy(tmp, "00", 2);
		else
			ft_putHexNbr(str[i], &tmp);
		d->map[where].hex[0] = tmp[0];
		d->map[where].hex[1] = tmp[1];
		d->map[where].recent = 20;
		d->map[where].champ = id;
		i++;
		where = where + 1 % MEM_SIZE;
	}
	return (0);
}





/*
int		changeMemVal(t_data *d, int id, int where, char *str)
{
	size_t i;
	size_t len;
	int index;

	i = 0;
	// writeL("changeMemVal");
	// writeL("where");
	// writeL(ft_itoa(where));
	// writeL("str:");
	// writeL(str);
	// sleep(2);
	len = ft_strlen(str);
	while (i + len <= REG_SIZE * 2 - 1)
	{
		d->map[where].hex[i % 2] = '0';
		d->map[where].recent = 20;
		d->map[where].champ = id;
		i++;
		if (i % 2 == 0)
			where = (where + 1) % MEM_SIZE;
		// where == (i % 2 == 0) ? ((where + 1) % MEM_SIZE) : where;
	}
	// writeL(ft_itoa(i));
	// writeL("max:");
	// writeL(ft_itoa(REG_SIZE * 2));
	// return (0);
	// sleep(10);
	index = 0;
	// return (0);
	while (i <= REG_SIZE * 2 - 1)
	{
		// writeL("before");
		// writeL(d->map[where].hex);
		d->map[where].hex[i % 2] = str[index];
		d->map[where].recent = 20;
		d->map[where].champ = id;
		// ft_strncpy(d->map[where].hex, &str[i], 2);
		// writeL("after");
		// writeL(d->map[where].hex);
		i++;
		index++;
		if (i % 2 == 0)
			where = (where + 1) % MEM_SIZE;
		// where == (i % 2 == 0) ? ((where + 1) % MEM_SIZE) : where;
	}
	// writeL(ft_itoa(REG_SIZE));
	// sleep(3);
	return (0);
}
*/