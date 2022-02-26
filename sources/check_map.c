/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:25:35 by jfremond          #+#    #+#             */
/*   Updated: 2022/01/26 11:40:14 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(int argc, char **argv, t_gnl *gnl, t_map *map)
{
	check_error_args(argc);
	check_validity_map(argv, gnl);
	check_error_map_size(argv, gnl, map);
	put_map_in_tab(argv, gnl, map);
	check_error_map_form(map);
	check_error_map_close(map);
	check_error_map_content(map);
}
