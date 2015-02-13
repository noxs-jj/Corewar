/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:30:01 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/13 19:37:36 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	convert_file(t_file *file)
{
	t_list	*tmp;

	tmp = file->lines;
	while (tmp)
	{
		LINE->bytecode = ft_memalloc(38);
		ft_strcpy(LINE->bytecode, "tito");
		tmp = tmp->next;
	}
}
