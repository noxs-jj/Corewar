/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_prog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 13:08:53 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/17 19:13:16 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	init_reg(t_header *new)
{
	int i;
	
	i = 0;
	while (i < REG_NUMBER + 1)
	{
		ft_bzero(new->reg[i], REG_SIZE); // init with 0 ?
		i++;
	}
}

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
	ft_strcpy((char *)cpy->prog, (char *)src->prog);//CAST
	ft_strcpy(cpy->comment, src->comment);
	cpy_reg(src, cpy);
}

t_header *lastProg(t_data *d)
{
	t_header *tmp;

	tmp = d->prog;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

t_header *searchProg(t_data *d, int number)
{
	t_header *prog;

	prog = d->prog;
	while (prog != NULL && (int)prog->number != number)
		prog = prog->next;
	return (prog);
}

t_header *newProg(int number)
{
	t_header 	*new;

	if ((new = (t_header *)malloc(sizeof(t_header))) == NULL)
	{
		writeL(ERR_PROG_ALLOC);
		sleep(5);														// remove
		return (NULL);
	}
	new->carry = false;
	new->lastLive = 0;
	new->liveNbr = 0;
	new->PC = NULL;
	new->indexPC = 0;
	ft_bzero(new->prog_name, PROG_NAME_LENGTH + 1);
	new->wait = 0;
	new->alive = true;
	new->number = number;
	new->nextOp = 0;
	new->filename = NULL;
	new->prog_size = 0;
	ft_bzero(new->prog, MEM_SIZE / MAX_PLAYERS + 2);
	ft_bzero(new->comment, COMMENT_LENGTH + 1);
	init_reg(new);
	ft_bzero(new->codage, 9);
	ft_bzero(new->opArgs, 4 * T_LAB);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

int		addProg(t_data *d, t_header *new)
{
	t_header *tmp;

	if (new == NULL)
		return (print_error(ERR_PROG_ALLOC));
	if (d->prog == NULL)
	{
		// writeL("create lst");
		// sleep(5);
		d->prog = new;
	}
	else
	{
		tmp = lastProg(d);
		// tmp = d->prog;
		// while (tmp->next != NULL)
		// 	tmp = tmp->next;
		new->prev = tmp;
		tmp->next = new;
		// writeL("add lst");
		// sleep(5);
	}
	return (0);
}

void delProg(t_data *d, int number)
{
	t_header *tmp;
	t_header *del;

	tmp = d->prog;
	while (tmp != NULL)
	{
		while (tmp != NULL && (int)tmp->number != number)
			tmp = tmp->next;
		if ((int)tmp->number == number)
		{
			del = tmp;
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			tmp = tmp->next;
			ft_memdel((void **)&del);
		}
	}
}

void delAll(t_data *d)
{
	int i;

	i = 1;
	while (i <= d->players)
	{
		delProg(d, i);
		i++;
	}
}
