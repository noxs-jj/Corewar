/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 10:16:08 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/01/14 10:24:39 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	char	*tmp;

	if (size > 0)
	{
		tmp = (void *)malloc(sizeof(unsigned char) * size);
		if (tmp == NULL)
			return (NULL);
		return (tmp);
	}
	else
		return (NULL);
}
