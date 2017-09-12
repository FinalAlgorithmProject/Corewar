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

int 			push_chmp(t_chmp **head, t_skrr *skrr)
{
	t_chmp *new_champ;

	if (!(new_champ = malloc(sizeof(t_chmp))))
		exit (0);
	init_data(new_champ, skrr);
	new_champ->next = *head;
	*head = new_champ;
	return (1);
}

unsigned int 	zero_reg(t_skrr *skrr)
{
	static char	nbr[4];
	static int 	cnt;
	static int 	cnt_player;
	int 		i;

	if (!*nbr)
	{
		i = -1;
		while (++i < 4)
			nbr[i] = 48;
	}
	if (ft_strchr(nbr, skrr->nbr_player + 48))
	{
		cnt_player++;
		nbr[cnt] = (char)(cnt_player + 48);
		cnt++;
		ft_printf("%s\n", nbr);
		return ((unsigned int) cnt_player * (-1));
	}
	else
	{
		nbr[cnt] = (char)(skrr->nbr_player + 48);
		cnt++;
		ft_printf("%s\n", nbr);
		return ((unsigned int) skrr->nbr_player * (-1));
	}
}

void 			init_data(t_chmp *champ, t_skrr *skrr)
{
	int i;

	i = -1;
	while (++i < REG_NUMBER)
		champ->registry[i] = 0;
	champ->registry[0] = zero_reg(skrr);
	champ->reg_n = 0;
	champ->offset = 0;
	champ->player_pos = 0;
	champ->cycle_to_die = CYCLE_TO_DIE;
	champ->nbr_live = 0;
	champ->carry = 0;
	champ->PC = 0;
}