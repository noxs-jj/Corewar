/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 12:09:54 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/03/19 12:09:55 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	twice_bzero(char (*buff)[], int buff_size, char (*str)[], int str_size)
{
	ft_bzero(buff, buff_size);
	ft_bzero(str, str_size);
}
