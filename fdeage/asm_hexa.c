/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_hexa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 23:22:07 by fdeage            #+#    #+#             */
/*   Updated: 2014/02/02 23:27:24 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern t_op	op_tab[17];

void	str_to_code(t_list *new, char *str)
{
	new = (t_list *)new;
	str = (char *)str;
}

void	code_param(t_line *line)
{
	int	i;
	int	exp_par;

	exp_par = 0;
	i = 0;
	while (i < 17)
	{
		if (line->str == (g_op_tab[i]).name)
		{
			line->code = (g_op_tab[i]).opcode;
			exp_par = (g_op_tab[i]).nb_params;
		}
		++i;
	}
}

int		b_conversion(int dec)
{
	char	*bin;
	int		res;

	bin = ft_itoa(dec);
	res = 0;
	return (res);
}

void	print_0(int n, int fd)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar_fd(0, fd);
		++i;
	}
}

void	print_hex(unsigned int hex, int fd)
{
	ft_putchar_fd((hex / (256 * 256 * 256)), fd);
	hex = hex - (256 * 256 * 256) * (hex / (256 * 256 * 256));
	ft_putchar_fd((hex / (256 * 256)), fd);
	hex = hex - (256 * 256) * (hex / (256 * 256));
	ft_putchar_fd((hex / 256), fd);
	hex = hex - (256) * (hex / (256));
	ft_putchar_fd(hex, fd);
}

