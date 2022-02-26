/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 10:08:07 by jfremond          #+#    #+#             */
/*   Updated: 2021/05/09 11:53:07 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 100

# include <unistd.h>
# include <stdlib.h>

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

char	*ft_strjoin(const char *s1, const char *s2);

size_t	ft_strlen(const char *str);

void	*ft_memmove(void *dest, const void *src, size_t n);

int		ft_newline(char *str);
int		get_next_line(int fd, char **line);

#endif
