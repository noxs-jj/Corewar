/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   co_printResult.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 15:00:49 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/13 15:00:50 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"
#include "../includes/render.h"

void	drawResultConsole(t_data *d)
{
	if (d->players > 0)
	{
		ft_putstr("* Player 1, weighing ");
		ft_putnbr(d->prog[0].prog_size);
		ft_putstr(S_C_BYTES);
		ft_putchar('"');
		ft_putstr(d->prog[0].prog_name);
		ft_putchar('"');
		ft_putstr(" (")
		ft_putchar('"');
		ft_putstr(d->prog[0].comment);
		ft_putchar('"');
		ft_putstr(") !\n");
	}
	if (d->players > 1)
	{
		ft_putstr("* Player 2, weighing ");
		ft_putnbr(d->prog[1].prog_size);
		ft_putstr(S_C_BYTES);
		ft_putchar('"');
		ft_putstr(d->prog[1].prog_name);
		ft_putchar('"');
		ft_putstr(" (")
		ft_putchar('"');
		ft_putstr(d->prog[1].comment);
		ft_putchar('"');
		ft_putstr(") !\n");
	}
	if (d->players > 2)
	{
		ft_putstr("* Player 3, weighing ");
		ft_putnbr(d->prog[2].prog_size);
		ft_putstr(S_C_BYTES);
		ft_putchar('"');
		ft_putstr(d->prog[2].prog_name);
		ft_putchar('"');
		ft_putstr(" (")
		ft_putchar('"');
		ft_putstr(d->prog[2].comment);
		ft_putchar('"');
		ft_putstr(") !\n");
	}
	if (d->players > 3)
	{
		ft_putstr("* Player 4, weighing ");
		ft_putnbr(d->prog[3].prog_size);
		ft_putstr(S_C_BYTES);
		ft_putchar('"');
		ft_putstr(d->prog[3].prog_name);
		ft_putchar('"');
		ft_putstr(" (")
		ft_putchar('"');
		ft_putstr(d->prog[3].comment);
		ft_putchar('"');
		ft_putstr(") !\n");
	}
	ft_putstr("Contestant ");
	ft_putstr(S_DEFAULT_VALUE); // player number
	ft_putstr(', ');
	ft_putchar('"');
	ft_putstr(S_DEFAULT_VALUE); // player name
	ft_putchar('"');
	ft_putstr(", has won !");
}
