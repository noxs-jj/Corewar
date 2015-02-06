/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 17:47:07 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/01/02 15:45:03 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;

	tmp = (t_list *)ft_memalloc(sizeof(t_list));
	if (content == NULL)
	{
		tmp->content = NULL;
		tmp->content_size = 0;
		tmp->next = NULL;
	}
	if (content != NULL)
	{
		tmp->content = ft_memalloc(content_size);
		tmp->content = ft_memmove(tmp->content, content, content_size);
		tmp->content_size = content_size;
		tmp->next = NULL;
		return (tmp);
	}
	return (NULL);
}
