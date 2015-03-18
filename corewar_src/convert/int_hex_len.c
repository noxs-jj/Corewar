/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_hex_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 14:43:29 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/03/18 14:43:30 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

int		int_hex_len(int n)
{
	int len;

	len = 1;
	while (n > 255)
	{
		n /= 255;
		len++;
	}
	return (len);
}
