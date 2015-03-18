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
	ft_putstr_fd("SEG 0\n", 2);
	if (init_start(d, ac, av) < 0)
		return (-1);
	writeL("SEGFAULT 1");
	if (read_files(d) < 0)
		return (-1);
	writeL("SEGFAULT 2");
	if (init_mem(d) < 0)
		return (-1);
	writeL("SEGFAULT 3");
	if (d->graphActiv == true)
		render_init(d);
	writeL("SEGFAULT 4");
	load_champions(d);
	writeL("SEGFAULT 5");
	gameStart(d);
	writeL("SEGFAULT 6");
	writeL("Game Done (main.c)");
	return (0);
}
