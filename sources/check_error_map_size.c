/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_map_size.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:19:58 by jfremond          #+#    #+#             */
/*   Updated: 2022/01/26 11:40:14 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_error_map_size(char **argv, t_gnl *gnl, t_map *map)
{
	gnl->fd = open(ft_strrev(argv[1]), O_RDONLY);
	gnl->ret = 1;
	while (gnl->ret == 1)
	{
		gnl->ret = get_next_line(gnl->fd, &gnl->line);
		++map->row;
		free(gnl->line);
	}
	close(gnl->fd);
	if (map->row < 3)
		print_error(ERR_MAP_SMALL);
}
