/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 16:25:21 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/18 16:32:45 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		init_mem(t_data *d)
{
	int		i;

	i = 0;
	if (MEM_SIZE > 4096 || MEM_SIZE < 1024)
		return (print_error(ERR_MAP_ALLOC));
	d->map = NULL;
	d->map = (t_case *)malloc(sizeof(t_case) * MEM_SIZE);
	if (d->map == NULL)
		return (print_error(ERR_MAP_ALLOC));
	while (i < MEM_SIZE)
	{
		d->map[i].hex[0] = '0';
		d->map[i].hex[1] = '0';
		d->map[i].hex[2] = 0;
		d->map[i].champ = 0;
		d->map[i].present = false;
		d->map[i].used = false;
		d->map[i].live = 0;
		i++;
	}
	return (0);
}