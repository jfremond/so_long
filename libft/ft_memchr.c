/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 18:19:51 by jfremond          #+#    #+#             */
/*   Updated: 2020/04/29 18:22:31 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned const char	*ptr_s;

	i = -1;
	ptr_s = (unsigned const char *)s;
	while (++i < n)
		if (ptr_s[i] == (unsigned char)c)
			return ((void *)&ptr_s[i]);
	return (NULL);
}
