/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 14:53:07 by yzakharc          #+#    #+#             */
/*   Updated: 2017/09/12 14:53:18 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtualm.h"

void	flag_n(char *nbr_player, t_skrr *skrr)
{
	int 	nbr;

	nbr = (int)ft_atoi(nbr_player);
	(nbr > 0 && nbr < 5) ? skrr->nbr_player = nbr : 0;
	skrr->j = nbr == 0 ? skrr->j + 1 : skrr->j + 2;
}