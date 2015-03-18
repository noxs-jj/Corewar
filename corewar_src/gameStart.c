/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameStart.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 16:15:00 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/17 18:45:02 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
** run the game
** call renderDraw at each execOp ?
*/

int		hex_strlen(unsigned char *str, int size)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (i < size && str[i] == 0)
		i++;
	while (i < size)
	{
		len++;
		i++;
	}
	return (len);
}

int		str_hex_len(unsigned char *str)
{
	unsigned int value;
	int len;

	len = 1;
	value = ft_hex2intdec(str);
	while (value > 255)
	{
		value /= 255;
		len++;
	}
	return (len);
}

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

void	nbr2hex(unsigned int n, unsigned char (*str)[])
{
	static char tab[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
							'a', 'b', 'c', 'd', 'e', 'f'};
	char		tmp[9];
	int 		i;
	int 		j;

	i = 8;
	ft_bzero(tmp, 9);
	while (n > 0 && i >= 0)
	{
		tmp[i] = tab[n % 16];
		n /= 16;
		i--;
	}
	if (i % 2 != 0)
		tmp[i] = '0';
	else
		i++;
	j = 0;
	while (i < 9)
	{
		(*str)[j] = tmp[i];
		i++;
		j++;
	}
}

void	hex2dec(unsigned char (*src)[], unsigned char (*str)[], int size)
{
	size_t len;
	int i;
	char tmp[3];
	int result;

	len = ft_strlen((char *)*src) / 2;
	i = 0;
	size = size - len;
	writeL("value");
	writeL(ft_itoa(size));
	writeL("len");
	writeL(ft_itoa(len));
	while (i < (int)len)
	{
		ft_bzero(tmp, 3);
		ft_strncpy(tmp, (char *)&(*src)[i * 2], 2);
		result = ft_hex2intdec((unsigned char *)tmp);
		(*str)[size + i] = result;
		i++;
	}
}

// conv arg dec to int
int		get_int_from_dec(char *str, int len)
{
	char	tmp[T_LAB + 1];
	int 	i;
	int		index;

	ft_bzero(tmp, T_LAB + 1);
	index = len - hex_strlen((unsigned char *)str, len);
	i = 0;
	len = len - index;
	while (len > 0)
	{
		ft_putHexNbr(str[index], (unsigned char (*)[])(&tmp[i]));  
		index++;
		len--;
		i += 2;
	}
	return ((int)ft_hex2intdec((unsigned char*)tmp));
}


/*
** conv hex str to int : ft_hex2intdec				ok
** conv "dec" str to hex str : ft_putNbr2hex		ok
** conv int to hex str : nbr2hex 					ok
** conv hex to "dec" str : hex2dec 					ok
**
*/

/*
**
** conv hex str to dec str (register) : str_to_reg	ok
** conv map hex to dec str (register) : map_to_reg	ok
** conv dec str (register) to int : reg_to_int		ok
** conv int to dec (register) : get_int_from_dec	ok
**
*/

int	gameStart(t_data *d)
{
	d->run = true;
	if (true == d->graphActiv)
		render_draw(d);
	else
		co_show_init_players(d);
	writeL("DUMP following");
	writeL(ft_itoa(d->dump));
	while (d->run == true)
	{
		usleep(d->ncurseSpeed);
		if (false == d->pause)
		{
			checkNextOp(d);
			execOp(d);
			if (true == d->graphActiv)
				render_draw(d);
			else
				render_shell(d);
			if (d->dump != -1 && (int)d->cycle == d->dump)
			{
				if (true == d->graphActiv)
					render_close(d);
				d->run = false;
				arg_dump(d);
			}
			checkCyles(d);
		}
		render_keyboard(d);
		if (true == d->pause)
			usleep(100000);
	}
	draw_result_console(d);
	return (0);
}
