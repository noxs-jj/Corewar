/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 18:30:32 by fdeage            #+#    #+#             */
/*   Updated: 2014/02/02 23:41:53 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern t_op	g_op_tab[17];

void    get_param_opcode(t_list *new)
{
	if (ft_strcmp(new->line->type, "T_REG      ") == 0)
		new->line->code = ft_atoi((new->line->str) + 1);
	else if (ft_strcmp(new->line->type, "T_DIR      ") == 0)
		new->line->code = ft_atoi((new->line->str) + 1);
	else if (ft_strcmp(new->line->type, "T_DIR_LABEL") == 0)
	{
		 ;
	}
	else if (ft_strcmp(new->line->type, "T_IND      ") == 0)
	{
		new->line->code = ft_atoi((new->line->str));
	}
}

void	get_label_opcode(t_list *new)
{
	new->line->code = -1;
	if (ft_strcmp(new->line->type, "instruction") == 0)
	{
		 ;
	}
	new->line->code = -1;
}

void	get_cmd_opcode(t_list *new, int i)
{
	if (ft_strcmp(new->line->type, "instruction") == 0)
	{
		while (i < 17)
		{
			if (ft_strcmp(new->line->str, (g_op_tab[i]).name) == 0)
			{
				new->line->code = (g_op_tab[i]).opcode;
				return ;
			}
			++i;
		}
		new->line->code = -1;
	}
}

int		get_cmd_parambyte(t_list *new, int bin)
{
	if (ft_strcmp(new->line->type, "T_REG      ") == 0)
		bin += 1000000;
	else if (ft_strcmp(new->line->type, "T_DIR      ") == 0
		|| ft_strcmp(new->line->type, "T_DIR_LABEL") == 0)
		bin += 10000000;
	else if (ft_strcmp(new->line->type, "T_IND      ") == 0)
		bin += 11000000;
	new = new->next;
	if (ft_strcmp(new->line->type, "T_REG      ") == 0)
		bin += 10000;
	else if (ft_strcmp(new->line->type, "T_DIR      ") == 0
    	|| ft_strcmp(new->line->type, "T_DIR_LABEL") == 0)
		bin += 100000;
	else if (ft_strcmp(new->line->type, "T_IND      ") == 0)
		bin += 110000;
	new = new->next;
	if (ft_strcmp(new->line->type, "T_REG      ") == 0)
		bin += 100;
	else if (ft_strcmp(new->line->type, "T_DIR      ") == 0
		|| ft_strcmp(new->line->type, "T_DIR_LABEL") == 0)
		bin += 1000;
	else if (ft_strcmp(new->line->type, "T_IND      ") == 0)
		bin += 1100;
	return (bin);
}

void	convert_file(t_list *root)
{
	t_list	*new;
	int		i;

	new = root;
	while (new->next)
	{
		i = 0;
		if (!(new->line->type))
			 ;
		else if (ft_strcmp(new->line->type, ".name      ") == 0
			|| ft_strcmp(new->line->type, ".comment   ") == 0)
			str_to_code(new, new->line->str);
		else if (ft_strcmp(new->line->type, "label      ") == 0)
			get_label_opcode(new);
		else if (ft_strcmp(new->line->type, "instruction") == 0)
			convert_params(new, i);
		new = new->next;
	}
}
