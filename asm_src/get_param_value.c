/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 14:23:56 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/28 17:18:56 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**  - get_param_value() gets the value of the token according to its type
** for labels it's a bit more tricky: LTOKEN points to the first token of the
** line: no line with no token
*/

static int	get_label_value(t_list *tmp, t_line *dir_line, t_line *lab_line)
{
	int		value;

	value = 0;
	if (dir_line->id > lab_line->id)
	{
		while (tmp && LINE != lab_line)
			tmp = tmp->next;
		while (tmp && LINE != dir_line)
		{
			value -= LINE->code_len;
			tmp = tmp->next;
		}
	}
	else if (dir_line->id < lab_line->id)
	{
		while (tmp && LINE != dir_line)
			tmp = tmp->next;
		while (tmp && LINE != lab_line)
		{
			value += LINE->code_len;
			tmp = tmp->next;
		}
	}
	return (value);
}

int			get_param_value(t_list *lines, t_line *srcline, t_token *token)
{
	t_list	*tmp;
	char	*label;

	if (token->type == T_A_REG || token->type == T_A_DIR)
		token->value = ft_atoi(token->str + 1);
	else if (token->type == T_A_IND)
		token->value = ft_atoi(token->str);
	else if (token->type == T_A_DLAB || token->type == T_A_INDLAB)
	{
		label = token->str + (token->type == T_A_DLAB ? 2 : 1);
		tmp = lines;
		while (tmp)
		{
			if (LINE->type == T_LABEL && !ft_strcmp(LINE->str, label))
			{
				token->value = get_label_value(lines, srcline, LINE);
				return (EXIT_SUCCESS);
			}
			tmp = tmp->next;
		}
		RET("Reference to an inexistent label.\n", EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
