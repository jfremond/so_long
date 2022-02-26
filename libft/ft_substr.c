/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 00:29:13 by jfremond          #+#    #+#             */
/*   Updated: 2021/06/03 10:17:22 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	count;
	size_t	size;
	char	*res;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	res = (char *)malloc(sizeof(*res) * (len + 1));
	if (!res)
		return (NULL);
	count = 0;
	while (count < len)
	{
		res[count] = s[start + count];
		count++;
	}
	res[count] = '\0';
	return (res);
}
