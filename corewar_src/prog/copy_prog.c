/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 16:01:11 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/03/18 16:01:12 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

void	copyProg(t_data *d, t_header *src, t_header *cpy)
{
	(void)d;
	cpy->carry = src->carry;
	cpy->lastLive = src->lastLive;
	cpy->liveNbr = src->liveNbr;
	cpy->PC = src->PC;
	cpy->indexPC = src->indexPC;
	ft_strcpy(cpy->prog_name, src->prog_name);
	cpy->wait = -1;
	cpy->alive = src->alive;
	cpy->number = src->number;
	cpy->nextOp = -1;
	cpy->filename = src->filename;
	cpy->prog_size = src->prog_size;
	ft_strcpy((char *)cpy->prog, (char *)src->prog);
	ft_strcpy(cpy->comment, src->comment);
	cpy_reg(src, cpy);
}
