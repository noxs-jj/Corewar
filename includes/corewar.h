/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 12:56:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/16 14:59:03 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//03 70 02 fe 38 
#ifndef COREWAR_H
# define COREWAR_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <ncurses.h>
# include <unistd.h>
# include <sys/types.h>

# define TIME_USLEEP		5000
# define PATH_DEBUGG		"../log/corewar.log"

# define ERR_PARAM "./corewar [-dump nbr_cycles] [[-n number] champion.cor]..."
# define ERR_FILE_DEBUGG "core corewar.log open error."
# define ERR_FILE "File doesn't exist"
# define ERR_READ "Read file error"
# define ERR_MAP_ALLOC "Malloc map error"
# define ERR_PROG_ALLOC "Malloc prog error"
# define INV_FILE "Invalid file"

# define BUFFSIZE 1

# define REG_NUMBER				16
# define REG_SIZE				4

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define MAX_PLAYERS			4
# define MAX_ARGS_NUMBER		(4 + 3 * MAX_PLAYERS)
# define PLAYER_NBR				4294967295

# define MEM_SIZE				(4 * 1024)
# define IDX_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			MEM_SIZE

# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"


# define CYCLE_TO_DIE			1500	// default 1536 test winner with 50
# define CYCLE_DELTA			50		// default 50
# define NBR_LIVE				21		// default 21
# define MAX_CHECKS				10		// default 10 test winner with 2

/*
** DIR 4 or 2 if has idx
** T_REG					1 registre : 01
** T_DIR					2 label ou nombre : 10
** T_IND					4 nombre : 11
** T_LAB					8 label
*/

# define REG 					1
# define DIR 					4
# define IND 					2

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

/*
** PROG_NAME_LENGTH 128
** COMMENT_LENGTH 2048
*/

# define PROG_NAME_LENGTH		128
# define COMMENT_LENGTH			2048
# define COREWAR_EXEC_MAGIC		"00ea83f3"

typedef struct 			s_bin
{
	char 				hex;
	char 				bin[4];
}						t_bin;

typedef struct 			s_dec
{
	char 				hex;
	unsigned int 		deci;
}						t_dec;

typedef struct			s_op
{
	char*				name;
	int					nb_params;
	int					param_types[4];
	int					opcode;
	int					nb_cycles;
	char*				description;
	int					has_pcode;
	int					has_idx;
}						t_op;

typedef struct			s_case
{
	unsigned char		hex[3];
	short int			champ;
	bool				present;
	bool				used;
	int 				recent;
	int 				live;
}						t_case;

typedef struct			s_header
{
	bool				carry;
	int					lastLive;
	int 				liveNbr;
	t_case				*PC;
	int					indexPC;
	char				prog_name[PROG_NAME_LENGTH + 1];
	int					wait;
	bool				alive;
	unsigned int		number;
	short int			nextOp;
	char 				*filename;
	unsigned int		prog_size;
	unsigned char		prog[MEM_SIZE];
	char				comment[COMMENT_LENGTH + 1];
	unsigned char 		reg[REG_NUMBER + 1][REG_SIZE];
	char 				codage[9];
	unsigned char		opArgs[4][T_LAB];
	struct s_header		*next;
	struct s_header		*prev;
}						t_header;

typedef	struct			s_data
{
	bool				graphActiv;
	bool				run;
	bool 				pause;
	int					cycleDie;
	int					fdDebugg;
	int 				dump;
	int 				players;
	int 				realPlayers;
	short int 			caseColor;
	int 				option_log;
	t_case				*map;
	t_header			*prog;
	unsigned int		periode;
	unsigned int 		cycle;
	unsigned int 		iCheckCycles;
	unsigned int 		iMaxCheck;
	unsigned int 		livesCurrent;
	unsigned int 		nbrWinner;
	unsigned int 		ncurseSpeed;
	WINDOW				*window;
}						t_data;

/* Corewar bin */
int				addProg(t_data *d, t_header *new);
int				arg_to_dec(char (*src)[]);
int				changeMemVal(t_data *d, int id, int where, char *str);
int				check_next_op(t_data *d);
int				exec_op(t_data *d);
int				get_arg_int(char *str);
int				get_arg_modulo(int n, int modulo);
int				get_int_from_dec(char *str, int len);
int				get_op_args(t_data *d, t_header *prog);
int				hex_strlen(unsigned char *str, int size);
int				init_mem(t_data *d);
int				init_start(t_data *d, int ac, char **av);
int				int_hex_len(int n);
int				is_direct(t_header *player, int arg_nbr);
int				is_indirect(t_header *player, int arg_nbr);
int				is_register(t_header *player, int arg_nbr);
int				is_valid_register(unsigned int reg);
int				load_champions(t_data *d);
int				print_error(char *str);
int				read_files(t_data *d);
int				read_op_code(t_data *d, t_header *prog);
int				reg_to_int(t_data *d, t_header *player, int reg);
int				set_option_log(t_data *d);
int				str_hex_len(unsigned char *str);
int 			game_start(t_data *d);
t_data			*get_data(void);
t_header		*lastProg(t_data *d);
t_header		*newProg(int number);
t_header		*searchProg(t_data *d, int number);
unsigned int	ft_hex_2_dec(unsigned char *str);
unsigned int	ft_hex2intdec(unsigned char *str);
void			arg_dump(t_data *d);
void			checkCyles(t_data *d);
void			copyProg(t_data *d, t_header *src, t_header *cpy);
void			delAll(t_data *d);
void			delProg(t_data *d, int number);
void			exitFree(void);
void			cpy_reg(t_header *src, t_header *cpy);
void			ft_putHexBNbr(unsigned int n, unsigned char (*str)[]);
void			ft_putHexNbr(unsigned char n, unsigned char (*str)[]);
void			hex2dec(unsigned char (*src)[], unsigned char (*str)[], int size);
void			init_reg(t_header *new);
void			int_to_reg(t_data *d, t_header *player, int n, int reg);
void			map_to_reg(t_data *d, t_header *player, int reg, int index);
void			nbr2hex(unsigned int n, unsigned char (*str)[]);
void			pc_advance(t_data *d, t_header *player, int adv);
void			str_to_reg(t_data *d, t_header *player, int reg, char *str);
void			write_l(char *str);
void 			ft_putNbr2hex(int len, unsigned char (*src)[], unsigned char (*str)[]);

/* OP functions */
typedef struct		s_opfunc
{
	int				op;
	int				(*func)(t_data *, t_header *);
}					t_opfunc;

int				op_add(t_data *d, t_header *player);
int				op_aff(t_data *d, t_header *player);
int				op_and(t_data *d, t_header *player);
int				op_fork(t_data *d, t_header *player);
int				op_ld(t_data *d, t_header *player);
int				op_ldi(t_data *d, t_header *player);
int				op_lfork(t_data *d, t_header *player);
int				op_live(t_data *d, t_header *player);
int				op_lld(t_data *d, t_header *player);
int				op_lldi(t_data *d, t_header *player);
int				op_or(t_data *d, t_header *player);
int				op_st(t_data *d, t_header *player);
int				op_sti(t_data *d, t_header *player);
int				op_sub(t_data *d, t_header *player);
int				op_xor(t_data *d, t_header *player);
int				op_zjump(t_data *d, t_header *player);

static const t_opfunc	g_opfunc[] =
{
	{1, &op_live},
	{2, &op_ld},
	{3, &op_st},
	{4, &op_add},
	{5, &op_sub},
	{6, &op_and},
	{7, &op_or},
	{8, &op_xor},
	{9, &op_zjump},
	{10, &op_ldi},
	{11, &op_sti},
	{12, &op_fork},
	{13, &op_lld},
	{14, &op_lldi},
	{15, &op_lfork},
	{16, &op_aff}
};


/* NCurses */
int 			render_init(t_data *d);
void			color_champ1(t_data *d, int i);
void			color_champ2(t_data *d, int i);
void			color_champ3(t_data *d, int i);
void			color_champ4(t_data *d, int i);
void			key_minux(t_data *d);
void			key_pause(t_data *d);
void			key_plus(t_data *d);
void			render_close(t_data *d);
void			render_draw(t_data *d);
void			render_init_pair(void);
void			render_keyboard(t_data *d);
void			render_legend_column(t_data *d);
void			render_legend_info_value(t_data *d);
void			render_legend_player_value(t_data *d);
void			render_legend_player_value1(t_data *d);
void			render_legend_player_value2(t_data *d);
void			render_legend_player_value3(t_data *d);
void			render_legend_player_value4(t_data *d);
void			render_legend_sentence(t_data *d);
void 			render_legend_player_sentence(t_data *d);

/* Shell Render */
void			co_info_player1(t_data *d, t_header *prog);
void			co_info_player2(t_data *d, t_header *prog);
void			co_info_player3(t_data *d, t_header *prog);
void			co_info_player4(t_data *d, t_header *prog);
void			co_show_init_players(t_data *d);
void			co_troll0(void);
void			co_troll1(void);
void			co_troll2(void);
void			co_troll3(void);
void			co_troll_all(void);
void			draw_result_console(t_data *d);
void			render_shell(t_data *d);

#endif
