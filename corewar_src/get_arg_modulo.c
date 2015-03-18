/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_modulo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 17:18:37 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/27 17:20:06 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
** apply modulo
*/

int		get_arg_modulo(int n, int modulo)
{
	if (n < 0)
		n = n % -modulo;
	else
		n = n % modulo;
	return (n);
}
