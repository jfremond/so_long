/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:18:17 by jfremond          #+#    #+#             */
/*   Updated: 2022/02/26 15:30:37 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_game(t_all *all)
{
	int	j;
	int	i;

	j = 0;
	while (j < all->map.row)
	{
		i = 0;
		while (i < all->map.col)
		{
			get_player_position(all, j, i);
			draw_fixed_elements(all, j, i);
			draw_collectibles(all, j, i);
			++i;
		}
		++j;
	}
	draw_player(all, all->coor.pos_y, all->coor.pos_x);
}
