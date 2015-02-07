/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 16:25:25 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/06 16:25:25 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_cmp	*s_lstCreate(char *string)
{
	t_cmd	*tmp;

	if (line != NULL)
	{
		tmp = (t_cmd *)malloc(sizeof(t_cmd));
		if (tmp == NULL)
			return (NULL);
		tmp->line = string;
		tmp->next = NULL;
		return (tmp);
	}
	return (NULL);
}

void	s_lstFreeLink(t_cmd *toDel)
{
	if (toDel != NULL)
	{
		ft_memdel((void **)todel->line);
		ft_memdel((void **)todel);
	}
}

void	s_lstAddEnd(t_cmd **lst, t_cmd *new)
{
	t_cmd	*tmp;

	if (*lst == NULL)
	{
		new->next = NULL;
		*lst = new;
	}
	else
	{
		tmp = *lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->next = NULL;
	}
}

void	s_lstDelAll(t_cmd **lst)
{
	t_cmd	*tmp;
	t_cmd	*toDel;

	tmp = *lst;
	while (tmp->next != NULL)
	{
		toDel = tmp;
		tmp = tmp->next;
		s_lstFreeLink(todel);
	}
}
