/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 10:48:19 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/01/09 14:31:09 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

int		ft_printf(const char *src, ...)
{
	size_t	strlen_display;
	va_list ap;
	size_t	i;

	strlen_display = 0;
	i = 0;
	va_start(ap, src);
	if (!src)
		_exit(0);
	while (src[i] != '\0')
	{
		if (src[i] == '\0')
			return (strlen_display);
		if (src[i] == 'c' && src[i - 1] == '%')
			ft_print_c(&ap, &i, &strlen_display);
		if (src[i] == '%' && src[i - 1] == '%')
			ft_print_pcent(&i, &strlen_display);
		if (src[i] == 's' && src[i - 1] == '%')
			ft_print_str(&ap, &i, &strlen_display);
		if (src[i] == 'd' && src[i - 1] == '%')
			ft_print_nbr_int(&ap, &i, &strlen_display);
		ft_print_no_param(&(*src), &i, &strlen_display);
	}
	va_end(ap);
	return (strlen_display);
}

void	ft_print_no_param(const char (*tmp), size_t *i, size_t *strlen_display)
{
	if (tmp[*i] != '%' && tmp[*i] != '\0')
	{
		ft_putchar(tmp[*i]);
		(*strlen_display)++;
		(*i)++;
	}
	if (tmp[*i] == '%')
		(*i)++;
}
