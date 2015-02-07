/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_init_start.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 11:45:28 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/07 11:45:30 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int 	init_start(t_asm *d)
{
	d = getASMdata();
	if (d == NULL)
	{
		fd_putstr_fd("asm-:init_start Memory initialisation error.\n", 2);
		return (-1);
	}
	d->fdSource = open(av[1], O_RDONLY);
	if (d->fdSource < 0)
	{
		fd_putstr_fd("asm-:init_start File open error.\n", 2);
		return (-1);
	}
	return (0);
}
