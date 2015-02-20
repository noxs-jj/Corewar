/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 23:34:21 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/19 19:22:16 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

# include<stdio.h>

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
