# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/28 22:15:55 by jfremond          #+#    #+#              #
#    Updated: 2022/02/25 15:54:52 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################
#   EXECUTABLE   #
##################

NAME	=	so_long

################
#   COMMANDS   #
################

CC		=	clang
LINK	=	clang
RM		=	/bin/rm -rf
MKDIR	=	/bin/mkdir -p

#############
#   FLAGS   #
#############

CFLAGS	=	-Wall -Wextra -Werror -c
CFLAGS	+=	-I $(INCS)
CFLAGS	+=	-MMD -MP -Imlx-linux
LDFLAGS	=	-L$(LIBFT_D) -lft -lXext -lX11 -lm -lmlx -Lmlx-linux
OUTPUT_OPTION	=	-o $@

###################
#   DIRECTORIES   #
###################

INCS	=	includes/

LIBFT_D	=	libft/
MLX_D	=	mlx-linux/

SRCS_D	=	sources/
GNL_D	=	get_next_line/

OBJS_D	=	objs/

##################
#   LIBRAIRIES   #
##################

LIBFT_A	=	libft.a
LIBFT_A	:=	$(addprefix $(LIBFT_D), $(LIBFT_A))

LIBMLX_A	=	libmlx.a
LIBMLX_A	:=	$(addprefix $(MLX_D), $(LIBMLX_A))

###############
#   SOURCES   #
###############

S_SRC	=	check_error_args.c			\
			check_error_map_close.c		\
			check_error_map_content.c	\
			check_error_map_form.c		\
			check_error_map_size.c		\
			check_map.c					\
			check_validity_map.c		\
			check_validity_texture.c	\
			clean_exit.c				\
			draw_collectibles.c			\
			draw_game.c					\
			draw_player.c				\
			free_tab.c					\
			get_player_position.c		\
			init_image.c				\
			init_struct.c				\
			key_press.c					\
			main.c						\
			mouse_click.c				\
			print_error.c				\
			put_map_in_tab.c			\
			resize_request.c			\
			set_sizes.c					\

S_GNL	=	get_next_line.c				\
			get_next_line_utils.c		\

###############
#   OBJECTS   #
###############

O_SRC	=	$(S_SRC:.c=.o)
O_SRC	:=	$(addprefix $(OBJS_D), $(O_SRC))


O_GNL	=	$(S_GNL:.c=.o)
O_GNL	:=	$(addprefix $(OBJS_D), $(O_GNL))

OBJS	=	$(O_SRC) $(O_GNL)

#############
#   RULES   #
#############

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT_A) $(LIBMLX_A)
			$(LINK) $(OBJS) $(LDFLAGS) $(OUTPUT_OPTION)

-include $(OBJS_D)*.d

$(OBJS_D)%.o:			$(SRCS_D)%.c
			$(MKDIR) $(OBJS_D)
			$(CC) $(CFLAGS) $(OUTPUT_OPTION) $<

$(OBJS_D)%.o:			$(GNL_D)%.c
			$(CC) $(CFLAGS) $(OUTPUT_OPTION) $<

$(MLX_D)libmlx.a:
			$(MAKE) -C $(MLX_D)

$(LIBFT_D)libft.a:
			$(MAKE) $(@F) -C $(@D)

clean:
			$(MAKE) clean -C $(MLX_D)
			$(MAKE) clean -C $(LIBFT_D)
			$(RM) $(OBJS_D)

fclean:		clean
			$(MAKE) fclean -C $(LIBFT_D)
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

