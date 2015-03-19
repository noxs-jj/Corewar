/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_prog.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 16:01:26 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/03/18 16:01:26 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_op_tab.h"

t_header *search_prog(t_data *d, int number)
{
	t_header *prog;

	prog = d->prog;
	while (prog != NULL && (int)prog->number != number)
		prog = prog->next;
	return (prog);
}
