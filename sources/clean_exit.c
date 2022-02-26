/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:47:03 by jfremond          #+#    #+#             */
/*   Updated: 2022/01/26 11:40:14 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_mlx(t_all *all)
{
	mlx_destroy_window(all->mlx.ptr, all->mlx.win);
	mlx_destroy_image(all->mlx.ptr, all->txt.player.img);
	mlx_destroy_image(all->mlx.ptr, all->txt.wall.img);
	mlx_destroy_image(all->mlx.ptr, all->txt.soil.img);
	mlx_destroy_image(all->mlx.ptr, all->txt.coll.img);
	mlx_destroy_image(all->mlx.ptr, all->txt.exit.img);
	mlx_destroy_image(all->mlx.ptr, all->img.img);
	mlx_destroy_display(all->mlx.ptr);
	free(all->mlx.ptr);
}

void	clean_exit(t_all *all)
{
	free_tab(all->map.tab);
	mlx_do_key_autorepeaton(all->mlx.ptr);
	printf("Total player moves : %d\n", all->player_moves);
	free_mlx(all);
	exit(EXIT_SUCCESS);
}
