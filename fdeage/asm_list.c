/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 14:47:54 by fdeage            #+#    #+#             */
/*   Updated: 2014/02/02 23:20:07 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_list	*list_new(t_line *line)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new->next = NULL;
	new->line = line;
	return (new);
}

void	list_pushback(t_list *begin_list, t_line *line)
{
	t_list	*new;
	t_list	*new2;

	new = begin_list;
	new2 = new;
	while (new->next)
	{
		new2 = new;
		new = new->next;
	}
	new->prev = new2;
	if (line)
	{
		new->next = list_new(line);
		(new->next)->prev = new;
	}
}

void	list_print(t_list *root, int fd_cor)
{
	t_list	*new;

	new = root;
	while (new->next)
	{
		ft_putstr_fd(new->line->str, fd_cor);
		new = new->next;
	}
	ft_putstr_fd(new->line->str, fd_cor);
}

void	list_free(t_list **root)
{
	t_list	*new1;
	t_list	*new2;

	if (*root)
	{
		new1 = *root;
		new2 = *root;
		while (new1->next)
		{
			new2 = new1;
			new1 = new1->next;
			free(new2);
		}
		free(new1);
	}
}

