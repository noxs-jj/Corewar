/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   co_infoPlayer4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 13:57:15 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/20 13:57:16 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

void	co_infoPlayer4(t_data *d)
{
	ft_putstr("* Player 4, weighing ");
	ft_putnbr(d->prog[3].prog_size);
	ft_putstr(S_C_BYTES);
	ft_putchar('"');
	ft_putstr(d->prog[3].prog_name);
	ft_putchar('"');
	ft_putstr(" (");
	ft_putchar('"');
	ft_putstr(d->prog[3].comment);
	ft_putchar('"');
	ft_putstr(") !\n");
}
