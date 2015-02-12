/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 13:20:33 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/12 17:18:52 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int main(int ac, char **av)
{
	t_data	d;
	if (init_start(&d, ac, av) < -1)
		return (-1);
	if (read_files(&d) < -1)
		return (-1);
	if (init_mem(&d) < 0)
		return (-1);
	if (LOG == 1)
		close(d.fdDebugg);
	return (0);
}