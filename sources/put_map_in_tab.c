/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map_in_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:39:08 by jfremond          #+#    #+#             */
/*   Updated: 2022/01/26 11:40:14 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_map_fill(t_gnl *gnl, t_map *map)
{
	free(map->tab);
	free(gnl->line);
	exit(EXIT_FAILURE);
}

void	put_map_in_tab(char **argv, t_gnl *gnl, t_map *map)
{
	int		fill;

	fill = 0;
	gnl->fd = open(argv[1], O_RDONLY);
	map->tab = (char **)malloc(sizeof(char *) * (map->row + 1));
	if (!map->tab)
		exit (0);
	map->tab[map->row] = NULL;
	gnl->ret = 1;
	while (gnl->ret == 1)
	{
		gnl->ret = get_next_line(gnl->fd, &gnl->line);
		map->col = ft_strlen(gnl->line);
		map->tab[fill] = ft_strdup(gnl->line);
		if (!map->tab[fill])
			free_map_fill(gnl, map);
		++fill;
		free(gnl->line);
	}
	close(gnl->fd);
}
