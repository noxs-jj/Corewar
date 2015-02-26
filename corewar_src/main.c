/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 13:20:33 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/26 14:54:32 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int main(int ac, char **av)
{
	t_data	*d = NULL;

	d = getData();
	if (init_start(d, ac, av) < 0)
		return (-1);
	// writeL("init start done");
	// call delAll(d) before exit (clear prog list)
	if (read_files(d) < 0)
		return (-1);
	// writeL("read_files done");
	// sleep(50);

	if (init_mem(d) < 0)
		return (-1);
	if (d->graphActiv == true)
		renderInit(d);
	load_champions(d);

	gameStart(d);// Main loop

	writeL("Game Done (main.c)");

	return (0);
}
