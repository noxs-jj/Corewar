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
	t_data	*d;

	d = NULL;
	d = get_data();
	if (init_start(d, ac, av) < 0)
		return (-1);
	if (read_files(d) < 0)
		return (-1);
	if (init_mem(d) < 0)
		return (-1);
	if (d->graph_activ == true)
		render_init(d);
	if (load_champions(d) < 0)
		return (-1);
	game_start(d);
	write_l("Game Done (main.c)");
	return (0);
}
