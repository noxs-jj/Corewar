/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 17:41:02 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/02/25 13:41:17 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	tmp = lst;
	while (tmp->next != NULL)
	{
		tmp = f(tmp);
		tmp = tmp->next;
	}
	return (tmp);
}
