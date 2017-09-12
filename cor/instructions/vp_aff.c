/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 18:39:31 by vpoltave          #+#    #+#             */
/*   Updated: 2017/09/02 18:39:32 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../virtual_machine/virtualm.h"

int 	aff_instr(t_skrr *skrr, t_chmp *chmp)
{
	unsigned char print_it;

	chmp->tmp_PC = chmp->PC + 2;
	print_it = (unsigned char)reg_param(skrr, &skrr->map[chmp->tmp_PC]);
	ft_printf("%c", (print_it % 256));
	return (1);
}