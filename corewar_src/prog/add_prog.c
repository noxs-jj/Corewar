/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 16:01:45 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/03/18 16:01:46 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

int		addProg(t_data *d, t_header *new)
{
	t_header *tmp;

	if (new == NULL)
		return (print_error(ERR_PROG_ALLOC));
	if (d->prog == NULL)
		d->prog = new;
	else
	{
		tmp = lastProg(d);
		new->prev = tmp;
		tmp->next = new;
	}
	return (0);
}
