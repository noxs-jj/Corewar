/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 11:29:33 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/12 11:44:59 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void    asm_error(const char *str)
{
    ft_putstr_color(str, COL_LIGHT_RED);
    exit(EXIT_FAILURE);
}
