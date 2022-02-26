/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:43:30 by jfremond          #+#    #+#             */
/*   Updated: 2021/12/12 09:57:07 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

# include "../mlx-linux/mlx.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "./keycodes.h"
# include "./error_message.h"

# define PLAYER "./textures/trainer_32x_V2.xpm"
# define COLL "./textures/pokeball_32x_V2.xpm"
# define WALL "./textures/tree_32x_V2.xpm"
# define SOIL "./textures/soil_32x_V2.xpm"
# define EXIT "./textures/exit_32x_V2.xpm"

/* Structures */
typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	int		win_width;
	int		win_height;
}				t_mlx;

typedef struct s_gnl
{
	int		i;
	int		fd;
	int		ret;
	char	*line;
}				t_gnl;

typedef struct s_map
{
	char	**tab;
	int		row;
	int		col;
	int		player;
	int		exit;
	int		collectible;
}				t_map;

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}				t_img;

typedef struct s_txt
{
	t_img	player;
	t_img	wall;
	t_img	soil;
	t_img	coll;
	t_img	exit;
}				t_txt;

typedef struct s_coor
{
	int	pos_x;
	int	pos_y;
}				t_coor;

typedef struct s_all
{
	t_mlx	mlx;
	t_gnl	gnl;
	t_map	map;
	t_img	img;
	t_txt	txt;
	t_coor	coor;
	int		player_moves;
	int		tile_size;
	int		max_width;
	int		max_height;
}				t_all;

/* Initialization */
void	init_struct(t_all *all);

/* Initialization images */
t_img	init_image(t_all *all, char *pathfile);
void	init_images(t_all *all);

/* Texture checks */
void	check_validity_texture(t_gnl *gnl, char *pathfile);
void	check_validity_textures(t_gnl *gnl);

/* Map checks */
void	check_error_args(int argc);
void	check_validity_map(char **argv, t_gnl *gnl);
void	check_error_map_size(char **argv, t_gnl *gnl, t_map *map);
void	check_error_map_form(t_map *map);
void	check_error_map_close(t_map *map);
void	check_error_map_content(t_map *map);
void	check_map(int argc, char **argv, t_gnl *gnl, t_map *map);

/* Store the map in a tab */
void	put_map_in_tab(char **argv, t_gnl *gnl, t_map *map);

/* Set sizes */
void	set_screen_size(t_all *all);
void	set_drawing_size(t_all *all);

/* Draw the game */
void	get_player_position(t_all *all);
void	draw_game(t_all *all);
void	draw_collectibles(t_all *all);
void	draw_player(t_all *all, int pos_x, int pos_y);

/* Events */
int		key_press(int keycode, t_all *all);
int		mouse_click(t_all *all);
int		resize_request(t_all *all);

/* Error gestion */
void	print_error(char *error_message);

/* Exit program */
void	free_tab(char **tab);
void	free_mlx(t_all *all);
void	clean_exit(t_all *all);

#endif
