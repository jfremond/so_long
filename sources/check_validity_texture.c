/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity_texture.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:42:30 by jfremond          #+#    #+#             */
/*   Updated: 2022/01/26 11:40:14 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_validity_texture(t_gnl *gnl, char *pathfile)
{
	pathfile = ft_strdup(pathfile);
	if (!pathfile)
		exit(1);
	gnl->fd = open(pathfile, O_RDONLY);
	if (gnl->fd < 0 || read(gnl->fd, gnl->line, 0) == -1
		|| ft_strncmp(ft_strrev(pathfile),
			"mpx.", 4) != 0 || !*(pathfile + 4) || *(pathfile + 4) == '/')
	{
		free(pathfile);
		print_error(ERR_TEXT);
	}
	free(pathfile);
	close(gnl->fd);
}

void	check_validity_textures(t_gnl *gnl)
{
	check_validity_texture(gnl, PLAYER);
	check_validity_texture(gnl, WALL);
	check_validity_texture(gnl, SOIL);
	check_validity_texture(gnl, COLL);
	check_validity_texture(gnl, EXIT);
}
