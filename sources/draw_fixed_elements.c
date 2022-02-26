/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fixed_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:16:00 by jfremond          #+#    #+#             */
/*   Updated: 2022/02/26 15:32:27 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_fixed_elements(t_all *all, int j, int i)
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
}
