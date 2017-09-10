/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 18:37:38 by vpoltave          #+#    #+#             */
/*   Updated: 2017/09/02 18:37:39 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../virtual_machine/virtualm.h"

int 	ldi_instr(t_skrr *skrr, t_chmp *chmp, int op)
{
	unsigned char	*q;
	int 			address;

	chmp->tmp_PC = chmp->PC + 1;
	if (&skrr->map[chmp->tmp_PC] == NULL)
		return (0);
	(!(q = malloc(sizeof(unsigned int) * 3))) ? exit (0) : 0;
	skrr->i = 0;
	if (g_tab[op].numb_of_arg != 3)
		instr_err(op);
	while (skrr->i < g_tab[op].numb_of_arg)
		q[skrr->i++] = arg_types(skrr, chmp, chmp->tmp_PC);
	address = get_address(q, skrr, chmp, 0);
	ft_printf("LDI (with pc and mod %d)\n", address);
	load_into(address, chmp, skrr, 2);
	chmp->PC += chmp->tmp_PC + 2;
	return (1);
}