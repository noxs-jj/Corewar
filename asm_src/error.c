/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 11:29:33 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/26 18:59:36 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "asm.h"
#include "libft.h"

void	asm_error(const char *str)
{
	ft_putstr_color(str, COL_LIGHT_RED);
	exit(EXIT_FAILURE);
}

void	print_detailed_error(t_file *file, const char *av1)
{
	(void)file;
	ft_putstr_color("Couldn't convert ", COL_LIGHT_RED);
	ft_putstr_color(av1, COL_LIGHT_YELLOW);
	ft_putstr_color(".\n", COL_LIGHT_RED);
}
