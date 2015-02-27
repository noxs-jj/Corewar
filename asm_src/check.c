/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 23:34:21 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/27 14:56:40 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"
#define G	g_op_tab[inst - 1]

extern t_op	g_op_tab[17];

/*
** check_label() makes sure that the initial '%' doesnt block the checking
** process
*/

int	has_name(t_file *file)
{
	if (!(file->has_name))
		return (0);
	return (1);
}

int	is_only_whitespace(const char *s)
{
	register size_t	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isspace(s[i]))
			return (0);
		++i;
	}
	return (1);
}

int	has_right_params(t_line *line)
{
	t_list	*tmp;
	size_t	inst;
	size_t	nb;
	int		new_type;

	if (!(tmp = line->tokens))
		return (1);
	inst = TOKEN->op->opcode;
	if (G.nb_params != (int)line->nb_params)
		RET("Wrong parameters number for the inst.\n", 0);
	if (!(tmp->next))
		return (0);
	tmp = tmp->next;
	nb = 0;
	while (tmp || (int)nb < G.nb_params)
	{
		new_type = (TOKEN->type == T_A_DLAB ? 2 : TOKEN->type - 8);
		new_type = (new_type == T_A_INDLAB - 8 ? 4 : new_type);
		if (new_type & ~G.param_types[nb])
			return (0);
		tmp = tmp->next;
		++nb;
	}
	return (1);
}

int	check_param(t_token *token, const char *s)
{
	register size_t	i;
	char			*check;

	check = LABEL_CHARS;
	i = 0;
	if (token->type == T_LABEL || token->type == T_A_DLAB
		|| token->type == T_A_INDLAB)
	{
		while (s[i])
		{
			if (!ft_strchr(LABEL_CHARS, s[i])
				&& !(i == 0 && s[i] == DIRECT_CHAR) && !((i == 0 || i == 1)
					&& s[i] == LABEL_CHAR))
				RET("Wrong char used in label.\n", EXIT_FAILURE);
			++i;
		}
		return (EXIT_SUCCESS);
	}
	else if (token->type == T_A_REG)
	{
		if (ft_atoi(token->str + 1) > REG_NUMBER)
			RET("Register number is too high.\n", EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
