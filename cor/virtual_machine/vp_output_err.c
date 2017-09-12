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

#include "virtualm.h"

void	instr_err(int op)
{
	if (op == 10)
		ft_printf("You changed number of args in %s :(\n", g_tab[op].name);
	else if (op == 11)
		ft_printf("You changed number of args in %s :(\n", g_tab[op].name);
	exit (op);
}