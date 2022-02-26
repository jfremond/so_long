/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_map_form.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:09:54 by jfremond          #+#    #+#             */
/*   Updated: 2022/01/26 11:40:14 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_error_map_form(t_map *map)
{
	int	i;
	int	j;
	int	len_i;
	int	len_j;

	i = 0;
	j = 1;
	while (map->tab[j])
	{
		len_i = ft_strlen(map->tab[i]);
		len_j = ft_strlen(map->tab[j]);
		if (len_i != len_j)
		{
			free_tab(map->tab);
			print_error(ERR_MAP_RECT);
		}
		++i;
		++j;
	}
}
