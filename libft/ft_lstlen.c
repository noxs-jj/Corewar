/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 13:35:50 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/01/02 15:44:52 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_lstlen(t_list **list)
{
	size_t	j;
	t_list	*tmp;

	if (list != NULL)
	{
		tmp = *list;
		j = 0;
		while (tmp != NULL)
		{
			tmp = tmp->next;
			j++;
		}
		return (j);
	}
	else
		return (0);
}
