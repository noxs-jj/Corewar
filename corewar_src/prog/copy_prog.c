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

void	copy_prog(t_data *d, t_header *src, t_header *cpy)
{
	(void)d;
	cpy->carry = src->carry;
	cpy->last_live = src->last_live;
	cpy->live_nbr = src->live_nbr;
	cpy->pc = src->pc;
	cpy->index_pc = src->index_pc;
	ft_strcpy(cpy->prog_name, src->prog_name);
	cpy->wait = -1;
	cpy->alive = src->alive;
	cpy->number = src->number;
	cpy->next_op = -1;
	cpy->filename = src->filename;
	cpy->prog_size = src->prog_size;
	ft_strcpy((char *)cpy->prog, (char *)src->prog);
	ft_strcpy(cpy->comment, src->comment);
	cpy_reg(src, cpy);
}
