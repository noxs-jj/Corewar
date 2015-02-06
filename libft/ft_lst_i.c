/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 15:49:45 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/03/19 15:49:46 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_lst_i	*ft_lstnew_i(int content)
{
	t_lst_i	*tmp;

	tmp = (t_lst_i *)ft_memalloc(sizeof(t_lst_i));
	tmp->content = content;
	tmp->next = NULL;
	return (tmp);
}

void	ft_lstadd_i(t_lst_i **alst, t_lst_i *new)
{
	if (*alst == NULL)
	{
		new->next = NULL;
		*alst = new;
	}
	else if (*alst != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
}

void	ft_lstaddend_i(t_lst_i **alst, t_lst_i *new)
{
	t_lst_i	*tmp;

	tmp = *alst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}
