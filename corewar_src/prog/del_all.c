/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 16:01:59 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/03/19 15:50:46 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_op_tab.h"

void	del_all(t_data *d)
{
	t_header	*del;
	t_header	*tmp;

	tmp = d->prog;
	while (tmp != NULL)
	{
		del = tmp;
		tmp = tmp->next;
		ft_memdel((void **)&del);
	}
}
