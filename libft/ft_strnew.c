/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 10:29:57 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/01/14 10:34:37 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*tmp;

	if (size < 65535)
	{
		tmp = (char *)ft_memalloc(size + 1);
		if (tmp == NULL)
			return (NULL);
		bzero(tmp, size + 1);
		return (tmp);
	}
	else
		return (NULL);
}
