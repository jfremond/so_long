/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 18:04:47 by jfremond          #+#    #+#             */
/*   Updated: 2020/04/29 18:07:53 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*ptr_d;
	unsigned const char	*ptr_s;

	i = 0;
	ptr_d = (unsigned char *)dest;
	ptr_s = (unsigned const char *)src;
	while (i < n)
	{
		ptr_d[i] = ptr_s[i];
		if (ptr_d[i] == (unsigned char)c)
			return ((void *)ptr_d + i + 1);
		i++;
	}
	return (NULL);
}
