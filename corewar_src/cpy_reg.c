/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_reg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 16:00:58 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/03/18 16:00:59 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	cpy_reg(t_header *src, t_header *cpy)
{
	int i;

	i = 0;
	while (i <= REG_NUMBER)
	{
		cpy->reg[i][0] = src->reg[i][0];
		cpy->reg[i][1] = src->reg[i][1];
		cpy->reg[i][2] = src->reg[i][2];
		cpy->reg[i][3] = src->reg[i][3];
		i++;
	}
}
