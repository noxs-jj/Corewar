/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 15:55:12 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/01/09 17:20:53 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_free_list(t_ldlc **alst)
{
	t_ldlc	*tmp;
	t_ldlc	*del;

	if (*alst != NULL)
	{
		tmp = *alst;
		tmp = tmp->next;
		while (tmp != *alst)
		{
			del = tmp;
			ft_memdel((void **)&del);
			tmp = tmp->next;
		}
		ft_memdel((void **)alst);
	}
}

int		ft_ldlc_len(t_ldlc **alst)
{
	t_ldlc	*tmp;
	int		i;

	if (*alst != NULL)
	{
		tmp = *alst;
		i = 1;
		tmp = tmp->next;
		while (tmp != *alst)
		{
			i++;
			tmp = tmp->next;
		}
		return (i);
	}
	else
		return (0);
}

int		ft_delone(t_ldlc *todel)
{
	if (todel != todel->prev)
	{
		todel->prev->next = todel->next;
		todel->next->prev = todel->prev;
		ft_memdel((void **)&todel);
		return (1);
	}
	return (0);
}

t_ldlc	*ft_ldlc(char *str)
{
	t_ldlc	*tmp;

	tmp = NULL;
	if (str != NULL)
	{
		tmp = (t_ldlc *)malloc(sizeof(t_ldlc));
		tmp->param = str;
		tmp->iselect = 0;
		tmp->cursed = 0;
		tmp->prev = NULL;
		tmp->next = NULL;
	}
	return (tmp);
}

void	ft_ldlcadd_end(t_ldlc **alst, t_ldlc *new)
{
	t_ldlc	*end;
	t_ldlc	*tmp;

	tmp = NULL;
	if (*alst == NULL)
	{
		new->prev = new;
		new->next = new;
		*alst = new;
	}
	else
	{
		end = (*alst)->prev;
		tmp = *alst;
		end->next = new;
		new->prev = end;
		tmp->prev = new;
		new->next = tmp;
	}
}
