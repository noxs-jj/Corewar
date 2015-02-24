/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_analysis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 20:46:55 by fdeage            #+#    #+#             */
/*   Updated: 2014/02/02 23:28:29 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern t_op	g_op_tab[17];

int		analyse_parsing(t_list *root)
{
	t_list	*new;

	new = root;
	while (new->next)
	{
		new = new->next;
	}
	return (EXIT_SUCCESS);
}

void	convert_params(t_list *new, int i)
{
	int	bin;

	get_cmd_opcode(new, i);
	new = new->next;
	bin = 0;
	if (g_op_tab[(new->prev)->line->code].has_pcode == 1)
		new->line->code = get_cmd_parambyte(new->next, bin);
	else
		new->line->code = -1;
	while (new->next && ((new->next)->line->type[0] == 'T'))
	{
		get_param_opcode(new);
		new = new->next;
	}
}
