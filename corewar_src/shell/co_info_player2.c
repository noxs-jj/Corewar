/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   co_info_player2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 13:57:08 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/26 15:09:30 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

void	co_info_player2(t_data *d, t_header *prog)
{
	ft_putstr("* Player 2, weighing ");
	ft_putnbr(prog->prog_size);
	ft_putstr(S_C_BYTES);
	ft_putchar('"');
	ft_putstr(prog->prog_name);
	ft_putchar('"');
	ft_putstr(" (");
	ft_putchar('"');
	ft_putstr(prog->comment);
	ft_putchar('"');
	ft_putstr(") !\n");
}
