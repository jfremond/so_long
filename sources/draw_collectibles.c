/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_collectibles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 09:49:56 by jfremond          #+#    #+#             */
/*   Updated: 2022/02/26 15:33:04 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_collectibles(t_all *all, int j, int i)
{
	if (all->map.tab[all->coor.pos_y][all->coor.pos_x] == 'C')
	{
		all->map.tab[all->coor.pos_y][all->coor.pos_x] = '0';
		--all->map.collectible;
	}
	if (all->map.tab[j][i] == 'C')
		mlx_put_image_to_window(all->mlx.ptr, all->mlx.win,
			all->txt.coll.img, i * all->tile_size, j * all->tile_size);
}
