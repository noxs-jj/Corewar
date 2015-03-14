/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameStart.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 16:15:00 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/14 16:40:49 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
** run the game
** call renderDraw at each execOp ?
*/

// return len of "dec" str (ex 1 1 0 == 3)
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
// conv unsigned int to hex str
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
}

/*
**  convert	45	99	5d
			69	153	93
** (4561245)
*/


// convert hex str to "dec" str
void	hex2dec(char (*src)[], char (*str)[])
{
	size_t len;
	int i;
	char tmp[3];
	int result;

	len = ft_strlen(*src) / 2;
	i= 0;
	while (i < len)
	{
		ft_bzero(tmp, 3);
		ft_strncpy(tmp, &(*src)[i * 2], 2);
		result = ft_hex2intdec(tmp);
		(*str)[i] = result; // error here char <- int (conv error)
		writeL("here");
		writeL(ft_itoa(result));

		i++;
	}
}

/*
** conv hex str to int : ft_hex2intdec
** conv "dec" str to hex str : ft_putNbr2hex
** conv int to "dec" str : ?
** conv hex to "dec" str : hex2dec
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
	// ft_putNbr2hex(hex_strlen(tab, 8), &tab, &result);
	hex2dec(&tab, &result); // convert hex str to "dec" str
	writeL(ft_itoa(result[0]));
	writeL(ft_itoa(result[1]));
	writeL(ft_itoa(result[2]));
	writeL(ft_itoa(result[3]));
	writeL(ft_itoa(result[4]));
	writeL(ft_itoa(result[5]));
	writeL(ft_itoa(result[6]));
	writeL(ft_itoa(result[7]));
	n = ft_hex2intdec(tab); // convert hex str to int
	// ft_bzero(tab, 9);
	// ft_putNbr2hex(hex_strlen(tab, 8), &result, &tab);

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
