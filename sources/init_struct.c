/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:29:56 by jfremond          #+#    #+#             */
/*   Updated: 2022/01/26 11:40:14 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_gnl_struct(t_gnl *gnl)
{
	gnl->i = 0;
	gnl->fd = 0;
	gnl->ret = 0;
	gnl->line = NULL;
}

static void	init_map_struct(t_map *map)
{
	map->tab = NULL;
	map->row = 0;
	map->col = 0;
	map->player = 0;
	map->exit = 0;
	map->collectible = 0;
}

static void	init_coor_struct(t_coor *coor)
{
	coor->pos_x = 0;
	coor->pos_y = 0;
}

void	init_struct(t_all *all)
{
	init_gnl_struct(&all->gnl);
	init_map_struct(&all->map);
	init_coor_struct(&all->coor);
	all->player_moves = 0;
	all->tile_size = 32;
}
