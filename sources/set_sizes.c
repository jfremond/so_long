/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sizes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 08:59:58 by jfremond          #+#    #+#             */
/*   Updated: 2022/01/26 11:40:14 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_screen_size(t_all *all)
{
	mlx_get_screen_size(all->mlx.ptr, &all->mlx.win_width,
		&all->mlx.win_height);
	all->max_width = all->map.col * all->tile_size;
	all->max_height = all->map.row * all->tile_size;
	if (all->max_width > all->mlx.win_width
		|| all->max_height > all->mlx.win_height)
	{
		if (all->max_width > all->mlx.win_width)
			all->max_width = all->mlx.win_width;
		else if (all->max_height > all->mlx.win_height)
			all->max_height = all->mlx.win_height;
	}
}

void	set_drawing_size(t_all *all)
{
	int	drawing_width;
	int	drawing_height;
	int	screen_size;
	int	drawing_size;

	drawing_width = all->map.col * all->tile_size;
	drawing_height = all->map.row * all->tile_size;
	drawing_size = drawing_width * drawing_height;
	screen_size = all->max_width * all->max_height;
	if (drawing_size > screen_size)
	{
		free_tab(all->map.tab);
		mlx_destroy_display(all->mlx.ptr);
		free(all->mlx.ptr);
		print_error(ERR_MAP_BIG);
	}
	if (all->tile_size != 32)
	{
		free_tab(all->map.tab);
		mlx_destroy_display(all->mlx.ptr);
		free(all->mlx.ptr);
		print_error(ERR_TILE_SIZE);
	}
}
