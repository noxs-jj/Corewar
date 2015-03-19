/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_prog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 16:01:51 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/03/18 16:01:52 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

void	del_prog(t_data *d, int number)
{
	t_header *tmp;
	t_header *del;

	tmp = d->prog;
	while (tmp != NULL)
	{
		while (tmp != NULL && (int)tmp->number != number)
			tmp = tmp->next;
		if ((int)tmp->number == number)
		{
			del = tmp;
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			tmp = tmp->next;
			ft_memdel((void **)&del);
		}
	}
}
