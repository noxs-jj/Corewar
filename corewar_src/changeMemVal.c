/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changeMemVal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 15:28:04 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/19 18:44:53 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
** not tested
*/

int		changeMemVal(t_data *d, int id, int where, char *str)
{
	size_t i;
	size_t len;

	i = 0;
	writeL("changeMemVal");
	writeL("where");
	writeL(ft_itoa(where));
	writeL("str:");
	writeL(str);
	sleep(5);
	len = ft_strlen(str);
	while (i + len < REG_SIZE)
	{
		d->map[where].hex[i % 2] = '0';
		i++;
		where == (i % 2 == 0) ? ((where + 1) % MEM_SIZE) : where;
	}
	while (i < REG_SIZE)
	{
		// writeL("before");
		// writeL(d->map[where].hex);
		d->map[where].hex[i % 2] = str[i];
		// ft_strncpy(d->map[where].hex, &str[i], 2);
		// writeL("after");
		// writeL(d->map[where].hex);
		i += 2;
		where == (i % 2 == 0) ? ((where + 1) % MEM_SIZE) : where;
	}
	writeL(ft_itoa(REG_SIZE));
	sleep(3);
	return (0);
}