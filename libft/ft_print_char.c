/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 13:07:15 by jmoiroux          #+#    #+#             */
/*   Updated: 2013/12/24 12:22:20 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

void	ft_print_c(va_list *ap, size_t *i, size_t *strlen_display)
{
	ft_putchar(va_arg(*ap, int));
	(*strlen_display)++;
	(*i)++;
}

void	ft_print_pcent(size_t *i, size_t *strlen_display)
{
	ft_putchar('%');
	(*strlen_display)++;
	(*i)++;
}

void	ft_print_str(va_list *ap, size_t *i, size_t *strlen_display)
{
	char	*to_print;

	to_print = NULL;
	to_print = va_arg(*ap, char*);
	if (to_print == NULL)
	{
		write(1, "(null)", 6);
		*strlen_display = *strlen_display + 6;
	}
	if (to_print != NULL)
	{
		ft_putstr(to_print);
		*strlen_display = *strlen_display + ft_strlen(to_print);
	}
	(*i)++;
}

void	ft_print_nbr_int(va_list *ap, size_t *i, size_t *strlen_display)
{
	char	*to_print;
	int		buff;

	to_print = NULL;
	buff = va_arg(*ap, int);
	if (buff == 0x0)
	{
		ft_putnbr(0);
		(*strlen_display)++;
	}
	if (buff != 0)
		to_print = ft_itoa(buff);
	ft_putstr(to_print);
	*strlen_display = *strlen_display + ft_strlen(to_print);
	(*i)++;
}
