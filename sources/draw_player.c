/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 09:50:33 by jfremond          #+#    #+#             */
/*   Updated: 2022/01/26 11:40:14 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_player(t_all *all, int pos_x, int pos_y)
{
	mlx_put_image_to_window(all->mlx.ptr, all->mlx.win,
		all->txt.player.img, pos_x * all->tile_size, pos_y * all->tile_size);
}
