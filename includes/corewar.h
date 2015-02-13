/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 12:56:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/13 17:22:13 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <ncurses.h>
#include <unistd.h>
#include <sys/types.h>

# define LOG				1
# define PATH_DEBUGG		"../log/corewar.log"

# define ERR_PARAM "./corewar [-dump nbr_cycles] [[-n number] champion.cor]..."
# define ERR_FILE_DEBUGG "core corewar.log open error."
# define ERR_FILE "File doesn't exist"
# define ERR_READ "Read file error"
# define ERR_MAP_ALLOC "Malloc map error"

# define BUFFSIZE 1

// #define IND_SIZE				2
#define REG_NUMBER				16
#define REG_SIZE				4
// #define DIR_SIZE				REG_SIZE

// # define REG_CODE				1
// # define DIR_CODE				2
// # define IND_CODE				3

#define MAX_PLAYERS				4
#define MAX_ARGS_NUMBER			(3 + 3 * MAX_PLAYERS)

#define MEM_SIZE				(4 * 1024)
#define IDX_MOD					(MEM_SIZE / 8)
#define CHAMP_MAX_SIZE			(MEM_SIZE / MAX_PLAYERS + 2)

// #define COMMENT_CHAR				'#'
// #define LABEL_CHAR				':'
// #define DIRECT_CHAR				'%'
// #define SEPARATOR_CHAR			','

// #define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"

// #define NAME_CMD_STRING			".name"
// #define COMMENT_CMD_STRING		".comment"


#define CYCLE_TO_DIE			1536
#define CYCLE_DELTA				50
#define NBR_LIVE				21
#define MAX_CHECKS				10

/*
**
*/

// typedef char	t_arg_type;

// #define T_REG					1
// #define T_DIR					2
// #define T_IND					4
// #define T_LAB					8

/*
**
*/

# define PROG_NAME_LENGTH		128	// 128
# define COMMENT_LENGTH			2048// 2048
// # define COREWAR_EXEC_MAGIC		0xea83f3


// typedef struct		s_op
// {
// 	char*			name;
// 	int				nb_params;
// 	int				param_types[4];
// 	int				opcode;
// 	int				nb_cycles;
// 	char*			description;
// 	int				has_pcode;
// 	int				has_idx;
// }					t_op;

// t_op    op_tab[17] =
// {
// 	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
// 	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
// 	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
// 	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
// 	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
// 	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
// 		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
// 	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
// 		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
// 	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
// 		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
// 	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
// 	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
// 		"load index", 1, 1},
// 	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
// 		"store index", 1, 1},
// 	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
// 	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
// 	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
// 		"long load index", 1, 1},
// 	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
// 	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
// 	{0, 0, {0}, 0, 0, 0, 0, 0}
// };


typedef struct			s_case
{
	unsigned char		hex[3];
	short int			champ; // champions's number ( 0 1 2 3 4 )
	short int			present; //is present ( 0 1 2 3 4 )
	bool				used; // true : yes, false : no
}						t_case;

typedef struct		s_header
{
	// unsigned int		magic;
	bool				carry; // true if prev action worked
	t_case				*PC; // program counter
	char				prog_name[PROG_NAME_LENGTH + 1];
	int					wait; // turn to wait before exec new instruction
	bool				alive; // is alive true or false
	unsigned int		number; // champions's number
	short int			nextOp;
	char 				*filename; // no malloc
	unsigned int		prog_size;
	unsigned char		prog[MEM_SIZE / MAX_PLAYERS + 2];
	char				comment[COMMENT_LENGTH + 1];
	char 				reg[REG_NUMBER][REG_SIZE];
}					t_header;

typedef	struct		s_data
{
	t_header		prog[MAX_PLAYERS];
	bool			run; // is run : y = true, n = false
	t_case			*map;
	int 			players; // player number
	int 			cycle; // nbr cycle done
	int 			dump; // dump option activated if dump != -1
	WINDOW			*window;
	int				fdDebugg; // file debug fd
	unsigned  int 	cycleDie;// = CYCLE_TO_DIE
}					t_data;

int		init_start(t_data *d, int ac, char **av);
int		print_error(char *str);
t_data	*getData(void);
void	writeL(char *str);
int		read_files(t_data *d);
void	init_prog(t_data *d);
void	ft_putHexNbr(unsigned char n, char (*str)[]);
int		init_mem(t_data *d);
int 	gameStart(t_data *d);
int		checkNextOp(t_data *d);
int		execOp(t_data *d);


// NCurses
void	renderClose(t_data *d);
void	renderDraw(t_data *d);
int 	renderInit(t_data *d);
void	renderLegendColumn(t_data *d);
void	renderLegendSentence(t_data *d);
void 	renderLegendPlayerSentence(t_data *d);
void	renderLegendPlayerValue(t_data *d);
void	renderLegendInfoValue(t_data *d);
void	renderInitPair(void);
void	renderLegendPlayerValue1(t_data *d);
void	renderLegendPlayerValue2(t_data *d);
void	renderLegendPlayerValue3(t_data *d);
void	renderLegendPlayerValue4(t_data *d);

#endif
