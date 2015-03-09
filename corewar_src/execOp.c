/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execOp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:19:06 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/09 12:15:16 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

// static void checkthis(t_data *d) // delete
// {
// 	t_header 	*prog;

// 	writeL("============");
// 	prog = lastProg(d);
// 	while (prog != NULL)
// 	{
// 		writeL("find a prog");
// 		writeL(ft_itoa(prog->number));
// 		prog = prog->prev;
// 	}
// 	writeL("/////////////////");
// 	prog = d->prog;
// 	while (prog != NULL)
// 	{
// 		writeL("find a prog");
// 		writeL(ft_itoa(prog->number));
// 		prog = prog->next;
// 	}
// 	sleep(5);
// }

int		execOp(t_data *d)
{
	t_header *prog;

	prog = lastProg(d);
	while (prog != NULL)
	{
		writeL("-----------");
		writeL("execOp");
		writeL(ft_itoa(prog->nextOp));
		writeL("wait");
		writeL(ft_itoa(prog->wait));
		writeL("codage");
		writeL(prog->codage);
		writeL("playerNbr");
		writeL(ft_itoa(prog->number));
		writeL("wait");
		writeL(ft_itoa(prog->wait));
		if (prog->wait == 1)
		{
			g_opfunc[prog->nextOp].func(d, prog);
			prog->wait--;
		}
		else if (prog->wait > 0)
			prog->wait--;
		prog = prog->prev;
		// sleep(5);
	}
	d->cycle++;
	return (0);
}
