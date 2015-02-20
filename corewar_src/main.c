/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 13:20:33 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/20 14:14:56 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int main(int ac, char **av)
{
	t_data	*d = NULL;

	d = getData();
	if (init_start(d, ac, av) < 0)
		return (-1);
	if (read_files(d) < 0)
		return (-1);
	if (init_mem(d) < 0)
		return (-1);
	if (d->graphActiv == true)
		renderInit(d);
	load_champions(d);

	gameStart(d);// Main loop

	return (0);
}
