# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/28 21:50:41 by jfremond          #+#    #+#              #
#    Updated: 2021/11/29 12:23:35 by jfremond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################
#   EXECUTABLE   #
##################

NAME	=	libft.a

################
#   COMMANDS   #
################

CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf
ARCH	=	ar -rcs

################
#   INCLUDES   #
################

INCS	=	libft.h

###############
#   SOURCES   #
###############

SRCS	=	char_in_str.c		\
			ft_atoi.c			\
			ft_bzero.c			\
			ft_calloc.c			\
			ft_isalnum.c		\
			ft_isalpha.c		\
			ft_isascii.c		\
			ft_isdigit.c		\
			ft_isprint.c		\
			ft_itoa.c			\
			ft_memccpy.c		\
			ft_memchr.c			\
			ft_memcmp.c			\
			ft_memcpy.c			\
			ft_memmove.c		\
			ft_memset.c			\
			ft_putchar_fd.c		\
			ft_putstr.c			\
			ft_putstr_fd.c		\
			ft_putendl_fd.c		\
			ft_putnbr_fd.c		\
			ft_split.c			\
			ft_strchr.c			\
			ft_strcmp.c			\
			ft_strdup.c			\
			ft_strjoin.c		\
			ft_strlcat.c		\
			ft_strlcpy.c		\
			ft_strlen.c			\
			ft_strmapi.c		\
			ft_strncmp.c		\
			ft_strnstr.c		\
			ft_strrchr.c		\
			ft_strrev.c			\
			ft_strtrim.c		\
			ft_substr.c			\
			ft_tolower.c		\
			ft_toupper.c		\
			ft_lstnew.c			\
			ft_lstadd_front.c	\
			ft_lstsize.c		\
			ft_lstlast.c		\
			ft_lstadd_back.c	\
			ft_lstdelone.c		\
			ft_lstclear.c		\
			ft_lstiter.c		\
			ft_lstmap.c			\

###############
#   OBJECTS   #
###############

O_LIB	=	$(SRCS:.c=.o)
OBJS	=	$(O_LIB) $(INCS)

#############
#   RULES   #
#############

$(NAME):	$(OBJS)
			$(ARCH) $(NAME) $(OBJS)

all:		$(NAME)

clean:
			$(RM) $(O_LIB)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
