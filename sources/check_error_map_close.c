/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_map_close.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:49:45 by jfremond          #+#    #+#             */
/*   Updated: 2022/01/26 11:40:14 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_error_map_close(t_map *map)
{
	int	j;
	int	i;

	j = 0;
	while (map->tab[j])
	{
		i = 0;
		while (map->tab[j][i])
		{
			if (map->tab[0][i] != '1' || map->tab[j][0] != '1'
			|| map->tab[map->row - 1][i] != '1'
			|| map->tab[j][map->col - 1] != '1')
			{
				free_tab(map->tab);
				print_error(ERR_MAP_CLOSE);
			}
			++i;
		}
		++j;
	}
}
