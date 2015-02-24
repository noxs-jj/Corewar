/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_label_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 17:14:16 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/24 11:20:55 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**  - get_param_value() gets the value of the token according to its type
** for labels it's a bit more tricky: LTOKEN points to the first token of the
** line: no line with no token
*/

//TODO: 27L
static int	get_label_value(t_list *tmp, t_line *dir_line, t_line *lab_line)
{
	int		value;
	//t_list	*tmp;

	value = 0;
	//tmp = lines;
	if (dir_line->id > lab_line->id)
	{
		//negative value
		while (tmp && LINE != lab_line)
			tmp = tmp->next;
		while (tmp && LINE != dir_line)
		{
			fprintf(stderr, "NEG old: %d val: %d new: %d\n", (int)value, (int)LINE->code_len, (int)(value - LINE->code_len));
			value -= LINE->code_len;
			tmp = tmp->next;
		}
	}
	else if (dir_line->id < lab_line->id)
	{
		//positive value
		while (tmp && LINE != dir_line)
			tmp = tmp->next;
		while (tmp && LINE != lab_line)
		{
			fprintf(stderr, "POS old: %d val: %d new: %d\n", (int)value, (int)LINE->code_len, (int)(value + LINE->code_len));
			value += LINE->code_len;
			tmp = tmp->next;
		}
	}
	return (value);
}

//OK - 23L
void		get_param_value(t_list *lines, t_line *srcline, t_token *token)
{
	t_list	*tmp;
	char	*label;

	fprintf(stderr, "TEST PARAM VALUE\n");
	if (token->type == T_A_REG || token->type == T_A_DIR)
		token->value = ft_atoi(token->str + 1);
	else if (token->type == T_A_IND)
		token->value = ft_atoi(token->str);
	else if (token->type == T_A_DLAB)
	{
		fprintf(stderr, "CONVERSION LABEL\n");
		label = token->str + 2;
		tmp = lines;
		fprintf(stderr, "CONVERSION LABEL2 - %s\n", LINE->str);
		while (tmp)
		{
			fprintf(stderr, "DATA = %s, data = %s\n", LINE->str, token->str + 2);
			if (LINE->type == T_LABEL && !ft_strcmp(LINE->str,
				token->str + 2))
			{
				fprintf(stderr, "label found, getting value...\n");
				token->value = get_label_value(lines, srcline, LINE);
				fprintf(stderr, "value found: %d\n", token->value);
				return ;
			}
			tmp = tmp->next;
		}
		ft_putstr("No matching label found.\n");
	}
	return ;
}
