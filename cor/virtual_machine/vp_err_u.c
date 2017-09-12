/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_virtual_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 14:12:55 by vpoltave          #+#    #+#             */
/*   Updated: 2017/08/16 15:49:32 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtualm.h"

void	init(t_skrr *skrr)
{
	skrr->fd = 0;
	skrr->i = 0;
	skrr->j = 0;
	skrr->n = 0;
	skrr->op = 0;
	skrr->shift = 0;
	skrr->flag = -1;
	skrr->nbr_player = 0;
//	skrr->ncurses_mode = 0;
	g_iter = 0;
	g_CTD = 0;
	skrr->chmp = NULL;
}

//TODO can move 'exit (0)' to botton of the func and delete '{}'
void	chk_open(t_skrr *skrr, char **argv, int argc, int flag)
{
	if (flag == 0)
		ft_printf("Too many champions! (Max %d)\n", MAX_PLAYERS);
	else if (flag == 1)
	{
//		chck_for_usage(skrr, *argv);
		skrr->fd = open(argv[skrr->j], O_RDONLY);
		if (skrr->fd < 0)
		{
			ft_printf("Can't read source file"RED" %s "RESET"\n", argv[skrr->j]);
			close(skrr->fd) < 0 ? exit(0) : 0;
			exit(flag);
		}
	}
	else if (flag == 2)
		ft_printf("Error: File"RED" %s "RESET"has an invalid header\n", *argv);
	else if (flag == 3)
		ft_printf("Error:"RED" %s "RESET"is a directory\n", *argv);
	(flag != 1) ? exit(flag) : 0;
}

//function for checking flags in usage. //TODO still need to get usage params

//void	chck_for_usage(t_skrr *skrr, char *argv)
//{
//	if (!ft_strcmp("-n", argv))
//		skrr->ncurses_mode = 1;
//	ft_printf("%s\nnmode: %d\n", argv, skrr->ncurses_mode);
//}

void	usage_e(void)
{
	ft_printf(YEL"Usage: ./corewar [-d N -s N -v N | -b --stealth | -n "
			  "--stealth] [-a] <champion1.cor> <...>\n"RESET
			  "    -a        : Prints output from \"aff\" (Default is to hide"
			  " it)\n"
			  CYN"TEXT OUTPUT MODE\n"RESET
			  "    -d N      : Dumps memory after N cycles then exits\n"
			  "    -s N      : Runs N cycles, dumps memory, pauses, then "
			  "repeats\n"
			  "    -v N      : Verbosity levels, can be added together to "
			  "enable several\n"
			  "                - 0 : Show only essentials\n"
			  "                - 1 : Show lives\n"
			  "                - 2 : Show cycles\n"
			  "                - 4 : Show operations (Params are NOT "
			  "litteral ...)\n"
			  "                - 8 : Show deaths\n"
			  "                - 16 : Show PC movements (Except for jumps)\n"
			  CYN"BINARY OUTPUT MODE\n"RESET
			  "    -b        : Binary output mode for corewar.42.fr\n"
			  "    --stealth : Hides the real contents of the memory\n"
			  CYN"NCURSES OUTPUT MODE\n"RESET
			  "    -n        : Ncurses output mode\n"
			  "    --stealth : Hides the real contents of the "
			  "memory\n");
}

void	chk_size(t_skrr *skrr, char *argv, unsigned char *line, t_chmp *chmp)
{
	skrr->i = 0;
	while (read(skrr->fd, &line, 1))
		skrr->i++;
	if (chmp->header.prog_size != skrr->i)
	{
		ft_printf("Error: File"RED" %s "RESET"has a code size that differ "
						  "from what its header says\n", argv);
		exit (0);
	}
	(lseek(skrr->fd, COMMANDS_POS, SEEK_SET) < 0) ? exit(0) : 0;
}
