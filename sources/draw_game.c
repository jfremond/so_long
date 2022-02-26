/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:18:17 by jfremond          #+#    #+#             */
/*   Updated: 2022/01/26 11:40:14 by jfremond         ###   ########.fr       */
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
			if (all->map.tab[j][i] == '1')
				mlx_put_image_to_window(all->mlx.ptr, all->mlx.win,
					all->txt.wall.img, i * all->tile_size, j * all->tile_size);
			if (all->map.tab[j][i] == '0')
				mlx_put_image_to_window(all->mlx.ptr, all->mlx.win,
					all->txt.soil.img, i * all->tile_size, j * all->tile_size);
			if (all->map.tab[j][i] == 'E')
				mlx_put_image_to_window(all->mlx.ptr, all->mlx.win,
					all->txt.exit.img, i * all->tile_size, j * all->tile_size);
			++i;
		}
		++j;
	}
	draw_collectibles(all);
}
