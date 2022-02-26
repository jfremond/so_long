/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:43:11 by jfremond          #+#    #+#             */
/*   Updated: 2022/01/26 11:40:14 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_validity_map(char **argv, t_gnl *gnl)
{
	char	*check_name;

	gnl->fd = open(argv[1], O_RDONLY);
	if (gnl->fd < 0)
		print_error(ERR_FILE_EXIST);
	if (read(gnl->fd, gnl->line, 0) == -1)
		print_error(ERR_FILE_DIRECTORY);
	if (ft_strncmp(ft_strrev(argv[1]), "reb.", 4) != 0)
		print_error(ERR_FILE_EXTENSION);
	check_name = argv[1];
	check_name += 4;
	if (!*check_name || *check_name == '/')
		print_error(ERR_FILE_NAME);
	close(gnl->fd);
}
