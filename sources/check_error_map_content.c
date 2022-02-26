/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_map_content.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:55:27 by jfremond          #+#    #+#             */
/*   Updated: 2022/01/26 11:40:14 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	count_char_map(t_map *map, char c)
{
	if (c == 'E')
		++map->exit;
	else if (c == 'C')
		++map->collectible;
	else if (c == 'P')
		++map->player;
}

static void	check_char_count(t_map *map)
{
	if (map->exit != 1)
	{
		free_tab(map->tab);
		print_error(ERR_MAP_EXIT);
	}
	else if (map->collectible == 0)
	{
		free_tab(map->tab);
		print_error(ERR_MAP_COLL);
	}
	else if (map->player != 1)
	{
		free_tab(map->tab);
		print_error(ERR_MAP_PLAYER);
	}
}

void	check_error_map_content(t_map *map)
{
	int	j;
	int	i;

	j = 0;
	while (map->tab[j])
	{
		i = 0;
		while (map->tab[j][i])
		{
			if (char_in_str("01PEC", map->tab[j][i]) == 0)
			{
				free_tab(map->tab);
				print_error(ERR_MAP_CHAR);
			}
			count_char_map(map, map->tab[j][i]);
			++i;
		}
		++j;
	}
	check_char_count(map);
}
