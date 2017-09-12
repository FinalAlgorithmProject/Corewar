/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 18:37:47 by vpoltave          #+#    #+#             */
/*   Updated: 2017/09/02 18:37:48 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../virtual_machine/virtualm.h"

int 			sti_instr(t_skrr *skrr, t_chmp *chmp, int op)
{
	unsigned char	*q;
	int 			address;
	short 			i;

	chmp->tmp_PC = chmp->PC + 1;
	if (&skrr->map[chmp->tmp_PC] == NULL)
		return (0);
	(!(q = malloc(sizeof(unsigned int) * 3))) ? exit (0) : 0;
	skrr->i = 0;
	if (g_tab[op].numb_of_arg != 3)
		instr_err(op);
	while (skrr->i < g_tab[op].numb_of_arg)
		q[skrr->i++] = arg_types(skrr, chmp, chmp->tmp_PC);
	i = from_reg(q, chmp, skrr);
	address = get_address(q, skrr, chmp, i);
	load_into(address, chmp, skrr);
	chmp->PC += chmp->offset + 2;
	ft_printf("STI (with pc and mod %d)\n", address);
	return (1);
}

short 		from_reg(unsigned char *q, t_chmp *chmp, t_skrr *skrr)
{
	unsigned short	i;

	i = 0;
	chmp->reg_n = 0; 															// maybe can delete this. already init this variable in [new_chmp.c].
	if (q[i] == T_REG && (chmp->tmp_PC += 1))
		chmp->reg_n = (unsigned int)reg_param(skrr, &skrr->map[skrr->chmp->tmp_PC]);
	else if (q[i] == T_DIR && (chmp->tmp_PC += 1))
		chmp->reg_n = (unsigned int)dir_param(skrr, &skrr->map[skrr->chmp->tmp_PC], g_tab[10].dir_size);
	else if (q[i] == T_IND && (chmp->tmp_PC += 1))
		chmp->reg_n =  (unsigned int)ind_param(skrr, &skrr->map[skrr->chmp->tmp_PC]);
	i++;
	return (i);
}

int 	get_address(unsigned char *q, t_skrr *skrr, t_chmp *chmp, short i)
{
	int adr;

	adr = 0;
	if (q[i] == T_REG && (chmp->tmp_PC += 1))
		adr = reg_param(skrr, &skrr->map[chmp->tmp_PC]);
	else if (q[i] == T_DIR && (chmp->tmp_PC += 1))
		adr = dir_param(skrr, &skrr->map[chmp->tmp_PC], g_tab[10].dir_size);
	else if (q[i] == T_IND && (chmp->tmp_PC += 1))
		adr = ind_param(skrr, &skrr->map[chmp->tmp_PC]);
	i++;
	if (q[i] == T_REG && (chmp->tmp_PC += 1))
		adr += reg_param(skrr, &skrr->map[chmp->tmp_PC]);
	else if (q[i] == T_DIR && (chmp->tmp_PC += 1))
		adr += dir_param(skrr, &skrr->map[chmp->tmp_PC], g_tab[10].dir_size);
	else if (q[i] == T_IND && (chmp->tmp_PC += 1))
		adr += ind_param(skrr, &skrr->map[chmp->tmp_PC]);
	adr = (chmp->PC + (adr % IDX_MOD));
	return (adr);
}
