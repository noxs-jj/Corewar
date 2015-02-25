/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 23:34:21 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/25 19:21:57 by fdeage           ###   ########.fr       */
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

int	has_final_comment(const char *str)
{
	register size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == FINAL_COMMENT_CHAR)
		{
			fprintf(stderr, "HAS FINAL COMMENT OK\n"); //virer
			return (1);
		}
		++i;
	}
	return (0);
}

/*
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
*/

int	has_right_params(t_line *line)
{
	t_list	*tmp;
	size_t	inst;
	size_t	nb;
	int		new_type;

	fprintf(stderr, "hasrightparam... line = %s\n", line->str);
	if (!(tmp = line->tokens))
		return (1);
	fprintf(stderr, "hrp 1 token = %p", tmp);
	inst = TOKEN->op->opcode;
	fprintf(stderr, " 2 ");
	if (G.nb_params != (int)line->nb_params)
		RET("Wrong parameters number for the inst.\n", 0);
	fprintf(stderr, " 3 ");
	if (!(tmp->next))
		return (0); //no param
	fprintf(stderr, " 4 ");
	tmp = tmp->next;
	nb = 0;
	fprintf(stderr, "inst: %s theor: %d, file: %d\n", G.name, G.nb_params, (int)line->nb_params);
	while (tmp || (int)nb < G.nb_params)
	{
		//fprintf(stderr, "TOKEN->type = %d = %d, expected = %d\n", TOKEN->type, TOKEN->type - 8, G.param_types[nb]);
		new_type = (TOKEN->type == T_A_DLAB ? 2 : TOKEN->type - 8);
		new_type = (new_type == T_A_INDLAB - 8 ? 4 : new_type);
		fprintf(stderr, "TOKEN->type = %d = %d, expected = %d\n", TOKEN->type, new_type, G.param_types[nb]);
		if (new_type & ~G.param_types[nb])
		{
			fprintf(stderr, "ERROR with the type of param\n"); //virer
			return (0);
		}
		tmp = tmp->next;
		++nb;
	}
	fprintf(stderr, "ok\n");
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
