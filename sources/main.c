/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 22:59:32 by jfremond          #+#    #+#             */
/*   Updated: 2022/02/26 15:43:20 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	start_mlx(t_all *all)
{
	all->mlx.ptr = mlx_init();
	if (!all->mlx.ptr)
	{
		free_tab(all->map.tab);
		exit(EXIT_FAILURE);
	}
	set_screen_size(all);
}

static void	create_mlx_window(t_all *all)
{
	all->mlx.win = mlx_new_window(all->mlx.ptr,
			all->max_width, all->max_height, "so_long");
	all->img.img = mlx_new_image(all->mlx.ptr,
			all->max_width, all->max_height);
}

static void	hook_functions(t_all *all)
{
	mlx_hook(all->mlx.win, 2, 1L << 0, key_press, &all->mlx);
	mlx_hook(all->mlx.win, 33, 1L << 17, mouse_click, &all->mlx);
	mlx_hook(all->mlx.win, 9, 1L << 21, resize_request, &all->mlx);
}

int	main(int argc, char **argv)
{
	t_all	all;

	init_struct(&all);
	check_map(argc, argv, &all.gnl, &all.map);
	check_validity_textures(&all.gnl);
	start_mlx(&all);
	set_drawing_size(&all);
	create_mlx_window(&all);
	init_images(&all);
	mlx_do_key_autorepeatoff(all.mlx.ptr);
	draw_game(&all);
	hook_functions(&all);
	mlx_loop(all.mlx.ptr);
	return (0);
}
