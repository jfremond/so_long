/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 22:43:00 by jfremond          #+#    #+#             */
/*   Updated: 2022/01/26 11:40:14 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_position(t_all *all)
{
	int	j;
	int	i;

	j = 0;
	while (all->map.tab[j])
	{
		i = 0;
		while (all->map.tab[j][i])
		{
			if (all->map.tab[j][i] == 'P')
			{
				all->coor.pos_x = i;
				all->coor.pos_y = j;
				all->map.tab[j][i] = '0';
			}
			++i;
		}
		++j;
	}
}
