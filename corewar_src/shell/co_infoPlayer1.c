/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   co_infoPlayer1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 13:57:04 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/20 13:57:05 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

void	co_infoPlayer1(t_data *d)
{
	ft_putstr("* Player 1, weighing ");
	ft_putnbr(d->prog[0].prog_size);
	ft_putstr(S_C_BYTES);
	ft_putchar('"');
	ft_putstr(d->prog[0].prog_name);
	ft_putchar('"');
	ft_putstr(" (");
	ft_putchar('"');
	ft_putstr(d->prog[0].comment);
	ft_putchar('"');
	ft_putstr(") !\n");
}
