/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:04:37 by jfremond          #+#    #+#             */
/*   Updated: 2022/01/26 11:40:14 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	init_image(t_all *all, char *pathfile)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(all->mlx.ptr, pathfile,
			&img.width, &img.height);
	img.addr = (int *)mlx_get_data_addr(img.img, &img.bpp,
			&img.line_length, &img.endian);
	if (!img.addr)
		clean_exit(all);
	return (img);
}

void	init_images(t_all *all)
{
	all->txt.player = init_image(all, PLAYER);
	all->txt.wall = init_image(all, WALL);
	all->txt.soil = init_image(all, SOIL);
	all->txt.coll = init_image(all, COLL);
	all->txt.exit = init_image(all, EXIT);
}
