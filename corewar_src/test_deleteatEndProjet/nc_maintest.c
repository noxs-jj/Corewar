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

	d->map = (char *)malloc(sizeof(char) * MEM_SIZE);
	if (d->map == NULL)
		return (print_error("Map malloc error"));

	while (i < MEM_SIZE)
	{
		d->map[i] = 0;
		i++;
	}


	renderInit(d);
	renderDraw(d);
	while (1)
		sleep(10);
	renderInit(d);

	return (0);
}
