/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:49:48 by jfremond          #+#    #+#             */
/*   Updated: 2022/01/27 12:07:40 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_player_moves_wa(int keycode, t_all *all)
{
	if ((keycode == W || keycode == UP)
		&& all->map.tab[all->coor.pos_y - 1][all->coor.pos_x]
		!= '1')
	{
		all->coor.pos_y -= 1;
		return (1);
	}
	if ((keycode == A || keycode == LEFT)
		&& all->map.tab[all->coor.pos_y][all->coor.pos_x - 1]
		!= '1')
	{
		all->coor.pos_x -= 1;
		return (1);
	}
	return (0);
}

int	check_player_moves(int keycode, t_all *all)
{
	if (check_player_moves_wa(keycode, all))
		return (1);
	if ((keycode == S || keycode == DOWN)
		&& all->map.tab[all->coor.pos_y + 1][all->coor.pos_x]
		!= '1')
	{
		all->coor.pos_y += 1;
		return (1);
	}
	if ((keycode == D || keycode == RIGHT)
		&& all->map.tab[all->coor.pos_y][all->coor.pos_x + 1]
		!= '1')
	{
		all->coor.pos_x += 1;
		return (1);
	}
	return (0);
}

int	key_press(int keycode, t_all *all)
{
	if (check_player_moves(keycode, all) == 1)
		++all->player_moves;
	if (keycode == ESC || (all->map.collectible == 0
			&& all->map.tab[all->coor.pos_y][all->coor.pos_x] == 'E'))
		clean_exit(all);
	printf("Player moves : %d\n", all->player_moves);
	draw_game(all);
	return (EXIT_SUCCESS);
}
