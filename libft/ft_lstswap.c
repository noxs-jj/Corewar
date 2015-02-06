/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 18:01:23 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/01/02 15:45:13 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstswap(t_list *a, t_list *b)
{
	void	*c_content;
	size_t	c_content_size;

	c_content = a->content;
	c_content_size = a->content_size;
	a->content = b->content;
	a->content_size = b->content_size;
	b->content = c_content;
	b->content_size = c_content_size;
}
