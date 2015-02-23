/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 23:34:21 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/23 20:37:53 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

#define G	g_op_tab[inst - 1]
extern t_op	g_op_tab[17];

# include<stdio.h>

int	check_file_2(t_file *file)
{
	(void)file;
	return (1);
}

int	is_only_whitespace(const char *s)
{
	register size_t	i;

	fprintf(stderr, "only whitespace:  ");
	i = 0;
	while (s[i])
	{
		fprintf(stderr, "%d", s[i]);
		if (!ft_isspace(s[i]))
		{
			fprintf(stderr, "\n");
			return (0);
		}
		++i;
	}
	fprintf(stderr, "\n");
	return (1);
}

int	has_final_comment(t_line *line)
{
	t_list	*tmp;

	tmp = line->tokens;
	while (tmp)
	{
		if (TOKEN->type == T_F_COMMENT)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	has_right_params(t_line *line)
{
	t_list	*tmp;
	size_t	inst;
	size_t	nb;

	tmp = line->tokens;
	inst = TOKEN->op->opcode;
	nb = G.nb_params;
	if (G.nb_params != (int)line->nb_params)
		RET("Wrong parameters number for the inst.\n", 0);
	while (tmp || nb)
	{
		if (TOKEN->type == T_A_REG && ((G.param_types[nb] & T_REG) != T_REG))
			return (0);
		if (TOKEN->type == T_A_DIR && ((G.param_types[nb] & T_DIR) != T_DIR))
			return (0);
		if (TOKEN->type == T_A_IND && ((G.param_types[nb] & T_IND) != T_IND))
			return (0);
		if (TOKEN->type == T_A_DLAB && ((G.param_types[nb] & T_DIR) != T_DIR))
			return (0);
		tmp = tmp->next;
		--nb;
	}
	return (1);
}

int	check_label(const char *s)
{
	register size_t	i;
	char			*check;

	check = LABEL_CHARS;
	i = 0;
	while (s[i] && s[i] != LABEL_CHAR)
	{
		if (!ft_strchr(check, s[i]))
			return (EXIT_FAILURE);
		++i;
	}
	return (EXIT_SUCCESS);
}
