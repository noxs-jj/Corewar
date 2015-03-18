/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 15:18:57 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/09 15:18:58 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

t_data	*get_data(void)
{
	static	t_data	*d = NULL;

	if (d == NULL)
	{
		d = (t_data *)malloc(sizeof(t_data));
		if (d == NULL)
			return (NULL);
	}
	return (d);
}
