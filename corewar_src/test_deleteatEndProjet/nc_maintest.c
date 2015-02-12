/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_maintest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 15:01:42 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/09 15:01:43 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"
#include "../../includes/render.h"
#include <time.h>

int	main(void)
{
	int 	i = 0;
	t_data *d = getData();

	init_mem(d);

	while (i < MEM_SIZE)
	{
		d->map[i].hex[0] = '0';
		d->map[i].hex[1] = '0';
		d->map[i].hex[2] = 0;
		d->map[i].champ = 0;
		d->map[i].present = 0;
		d->map[i].used = false;
		i++;
	}

	d->map[255].hex[0] = 'f';
	d->map[255].hex[1] = '0';
	d->map[255].champ = 2;
	d->map[255].present = 2;
	d->map[255].used = true;

	d->map[360].hex[0] = 'Z';
	d->map[360].hex[1] = '4';
	d->map[360].champ = 1;
	d->map[360].present = 1;
	d->map[360].used = false;

	d->map[2045].hex[0] = '5';
	d->map[2045].hex[1] = 'h';
	d->map[2045].champ = 3;
	d->map[2045].present = 3;
	d->map[2045].used = false;

	d->map[3000].hex[0] = 'd';
	d->map[3000].hex[1] = 'j';
	d->map[3000].champ = 4;
	d->map[3000].present = 4;
	d->map[3000].used = true;

	d->map[1500].hex[0] = 'Q';
	d->map[1500].hex[1] = 'R';
	d->map[1500].champ = 1;
	d->map[1500].present = 1;
	d->map[1500].used = true;


	renderInit(d);
	renderDraw(d);
	while (1)
		sleep(10);
	renderInit(d);

	return (0);
}
