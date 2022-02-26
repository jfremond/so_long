/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 10:06:32 by jfremond          #+#    #+#             */
/*   Updated: 2021/10/14 17:42:54 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(*line) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_get_rest(char *str)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	rest = (char *)malloc(sizeof(*rest) * ((ft_strlen(str) - i) + 1));
	if (!rest)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		rest[j++] = str[i++];
	rest[j] = '\0';
	free(str);
	return (rest);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*rest;
	int			to_read;

	to_read = 1;
	buf = (char *)malloc(sizeof(*buf) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE <= 0 || !line || !buf)
		return (-1);
	while (!ft_newline(rest) && to_read != 0)
	{
		to_read = read(fd, buf, BUFFER_SIZE);
		if (to_read == -1)
		{
			free(buf);
			return (-1);
		}
		buf[to_read] = '\0';
		rest = ft_strjoin(rest, buf);
	}
	free(buf);
	*line = ft_get_line(rest);
	rest = ft_get_rest(rest);
	if (to_read == 0)
		return (0);
	return (1);
}
