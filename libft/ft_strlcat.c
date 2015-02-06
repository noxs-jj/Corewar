/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:21:36 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/01/02 15:47:42 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	t1;
	size_t	t2;

	t1 = ft_strlen(src);
	t2 = ft_strlen(dst);
	if (t2 < size)
	{
		ft_strncat(dst, src, size - t2 - 1);
		return (t1 + t2);
	}
	else
		return (size + t1);
}
