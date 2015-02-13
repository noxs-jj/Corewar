/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 17:00:38 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/13 15:06:04 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static void	init_reg(t_data *d, int number)
{
	int i;
	int j;

	i = 0;
	while (i < REG_NUMBER)
	{
		j = 0;
		while (j < REG_SIZE)
		{
			d->prog[number].reg[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	init_prog(t_data *d)
{
	int	i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		d->prog[i].carry = false;
		d->prog[i].PC = NULL;
		ft_bzero(d->prog[i].prog_name, PROG_NAME_LENGTH + 1);
		d->prog[i].number = 0;
		d->prog[i].filename = NULL;
		d->prog[i].prog_size = 0;
		ft_bzero(d->prog[i].prog, MEM_SIZE / MAX_PLAYERS + 2);
		ft_bzero(d->prog[i].comment, COMMENT_LENGTH + 1);
		init_reg(d, i);
		i++;
	}
}