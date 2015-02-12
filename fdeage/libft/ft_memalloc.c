/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 18:54:26 by fdeage            #+#    #+#             */
/*   Updated: 2015/01/28 15:37:25 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** equivalent to calloc(): allocates AND sets the memory to 0
*/

void	*ft_memalloc(size_t size)
{
	void			*new;
	register char	*ptr;

	if (!(new = (void *)malloc(size * sizeof(void *))))
		return (NULL);
	ptr = (char *)new;
	while (size--)
		*ptr++ = (char)0;
	return (new);
}
