/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 16:01:19 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/03/18 16:01:19 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

t_header *lastProg(t_data *d)
{
	t_header *tmp;

	tmp = d->prog;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
