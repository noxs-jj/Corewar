/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameStart.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 16:15:00 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/14 16:15:14 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
** run the game
** call renderDraw at each execOp ?
*/

int		hex_strlen(char *str, int size)
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

int		str_hex_len(char *str)
{
	int value;
	int len;

	len = 1;
	value = ft_hex2intdec(str);
	// writeL("value");
	// writeL(ft_itoa(value));
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

// OK !!
// conv unsigned int to "dec" str
// first int to hex str, snd hex str to "dec" str
void	nbr2hex(unsigned int n, char (*str)[])
{
	static char tab[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
							'a', 'b', 'c', 'd', 'e', 'f'};
	char		tmp[9];
	int i;
	int j;
	// int len;

	i = 8;
	ft_bzero(tmp, 9);
	// len = hex_len(n);
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
	writeL(&(*str)[0]);
	writeL(&(*str)[1]);
	writeL(&(*str)[2]);
	writeL(&(*str)[3]);
	writeL(&(*str)[4]);
	writeL(&(*str)[5]);
	writeL(&(*str)[6]);
	writeL(&(*str)[7]);
	writeL(&(*str)[8]);
}

/*
** conv hex str to int : ft_hex2intdec
** conv "dec" str to hex str : ft_putNbr2hex
** conv int to "dec" str : ?
** conv hex to "dec" str : ?
**
*/

void ft_check()
{
	char tab[9];
	char result[9];
	int n;

	ft_bzero(tab, 9);
	ft_bzero(result, 9);
	// tab[5] = 1;
	// tab[6] = 0;
	// tab[7] = 0;
	writeL("================");
	
	// ft_putNbr2hex(hex_strlen(tab, 8), &tab, &result);
	nbr2hex(4561245, &tab);
	ft_putNbr2hex(hex_strlen(tab, 8), &tab, &result);
	n = ft_hex2intdec(tab); // convert hex str to int
	writeL("tab");
	writeL(tab);
	writeL("result");
	writeL(result);
	writeL("number");
	writeL(ft_itoa(n));

	sleep(10);
}

int	gameStart(t_data *d)
{
	ft_check();
	d->run = true;
	if (true == d->graphActiv)
		render_draw(d); // need to be modified (d->prog)
	else
		co_show_init_players(d); // need to be modified (d->prog)
	writeL(ft_itoa("DUMP following"));
	writeL(ft_itoa(d->dump));
	while (d->run == true)
	{
		usleep(d->ncurseSpeed);
		if (false == d->pause)
		{
			checkNextOp(d); // check next champion's instruction (ptr by PC)
			execOp(d); // exec next op defined in d->prog[player].nextOp
			if (true == d->graphActiv)
				render_draw(d); // draw game with ncurses // need to be modified (d->prog)
			else
				render_shell(d); // draw game on shell // need to be modified (d->prog)
			if (d->dump != -1 && d->cycle == d->dump)
			{
				if (true == d->graphActiv)
					render_close(d); // need to be modified (d->prog)
				d->run = false;
				arg_dump(d); // need to be modified (d->prog)
			}
			checkCyles(d); // need to be modified (d->prog)
		}
		keyboard(&d); // need to be modified (d->prog)
		if (true == d->pause)
			usleep(100000); 						// REMOVE
	}
	draw_result_console(d); // need to be modified (d->prog)
	return (0);
}
