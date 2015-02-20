/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   co_infoPlayer3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 13:57:12 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/20 13:57:13 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

void	co_infoPlayer3(t_data *d)
{
	ft_putstr("* Player 3, weighing ");
	ft_putnbr(d->prog[2].prog_size);
	ft_putstr(S_C_BYTES);
	ft_putchar('"');
	ft_putstr(d->prog[2].prog_name);
	ft_putchar('"');
	ft_putstr(" (");
	ft_putchar('"');
	ft_putstr(d->prog[2].comment);
	ft_putchar('"');
	ft_putstr(") !\n");
}
