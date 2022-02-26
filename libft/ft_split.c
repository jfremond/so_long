/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 19:47:42 by jfremond          #+#    #+#             */
/*   Updated: 2021/06/03 10:19:18 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			words++;
		i++;
	}
	return (words);
}

static int	len_words(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s && *s != c)
	{
		s++;
		count++;
	}
	return (count);
}

static char	**ft_free_split(char **tab)
{
	size_t	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	char	**tab;

	j = 0;
	tab = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!s || !tab)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			i = 0;
			tab[j] = (char *)malloc(sizeof(*s) * (len_words(s, c) + 1));
			if (!tab[j])
				return (ft_free_split(tab));
			while (*s && *s != c)
				tab[j][i++] = (char)*s++;
			tab[j++][i] = '\0';
		}
	}
	tab[j] = NULL;
	return (tab);
}
