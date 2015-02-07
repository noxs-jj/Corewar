/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 15:37:29 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/06 15:37:30 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm_compil.h"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		fd_putstr_fd("asm-: Need 1 arguments: './asm file.s'\n", 2);
		return (-1);
	}
	if (init_start(av) < 0)
	{
		fd_putstr_fd("Initialiation Failed'\n", 2);
		return (-1);
	}
	return (0);
}
