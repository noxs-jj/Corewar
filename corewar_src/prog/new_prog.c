/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_prog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 16:01:32 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/03/18 16:01:32 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

static void	new_prog_2(t_header *new, int number)
{
	ft_bzero(new->prog_name, PROG_NAME_LENGTH + 1);
	new->wait = 0;
	new->alive = true;
	new->number = number;
	new->nextOp = 0;
	new->filename = NULL;
	new->prog_size = 0;
	ft_bzero(new->prog, MEM_SIZE);
	ft_bzero(new->comment, COMMENT_LENGTH + 1);
	init_reg(new);
	ft_bzero(new->codage, 9);
	ft_bzero(new->opArgs, 4 * T_LAB);
	new->next = NULL;
	new->prev = NULL;
}

t_header	*new_prog(int number)
{
	t_header	*new;

	if ((new = (t_header *)malloc(sizeof(t_header))) == NULL)
	{
		write_l(ERR_PROG_ALLOC);
		sleep(5);
		return (NULL);
	}
	new->carry = false;
	new->lastLive = 0;
	new->liveNbr = 0;
	new->PC = NULL;
	new->indexPC = 0;
	new_prog_2(new, number);
	return (new);
}
