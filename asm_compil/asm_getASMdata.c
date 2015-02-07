/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_getASMdata.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 15:42:14 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/06 15:42:14 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm_compil.h"

t_asm	*getASMdata( void )
{
	static t_asm 	*d = NULL;

	if (d == NULL)
	{
		d = (t_asm *)malloc(sizeof(t_asm));
		if (d == NULL)
			return (NULL);
	}
	return (d);
}
